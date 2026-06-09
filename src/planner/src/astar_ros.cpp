#include "planner/astar_ros.hpp"
#include <string>
#include <memory>

namespace planner
{

AStarROS::AStarROS(const rclcpp::NodeOptions& options)
    : Node("astar_planner", options)
    , map_received_(false)
{
    // 声明参数
    this->declare_parameter<double>("heuristic_weight", 1.0);
    this->declare_parameter<bool>("use_8_connectivity", true);
    this->declare_parameter<std::string>("map_topic", "/inflated_map");
    this->declare_parameter<std::string>("base_frame", "base_link");
    this->declare_parameter<std::string>("global_frame", "map");

    // 配置 A* 搜索算法
    AStarConfig config;
    config.heuristic_weight = this->get_parameter("heuristic_weight").as_double();
    config.use_8_connectivity = this->get_parameter("use_8_connectivity").as_bool();
    astar_.setConfig(config);

    std::string map_topic = this->get_parameter("map_topic").as_string();
    std::string base_frame = this->get_parameter("base_frame").as_string();
    std::string global_frame = this->get_parameter("global_frame").as_string();

    // 初始化 TF2
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // 创建订阅
    map_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
        map_topic, rclcpp::QoS(1).transient_local(),
        std::bind(&AStarROS::mapCallback, this, std::placeholders::_1));

    goal_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
        "/goal_pose", rclcpp::QoS(10),
        std::bind(&AStarROS::goalCallback, this, std::placeholders::_1));

    // 创建发布
    path_pub_ = this->create_publisher<nav_msgs::msg::Path>("/path", rclcpp::QoS(10));

    RCLCPP_INFO(this->get_logger(), "A* Planner ROS node initialized.");
    RCLCPP_INFO(this->get_logger(), "  heuristic_weight: %.2f", config.heuristic_weight);
    RCLCPP_INFO(this->get_logger(), "  use_8_connectivity: %s",
                config.use_8_connectivity ? "true" : "false");
    RCLCPP_INFO(this->get_logger(), "  frames: %s -> %s", global_frame.c_str(), base_frame.c_str());
    RCLCPP_INFO(this->get_logger(), "Waiting for map on '%s' topic...", map_topic.c_str());
}

bool AStarROS::getRobotPose(double& x, double& y)
{
    std::string base_frame = this->get_parameter("base_frame").as_string();
    std::string global_frame = this->get_parameter("global_frame").as_string();

    try {
        geometry_msgs::msg::TransformStamped transform = tf_buffer_->lookupTransform(
            global_frame, base_frame, tf2::TimePointZero, tf2::durationFromSec(1.0));

        x = transform.transform.translation.x;
        y = transform.transform.translation.y;
        return true;
    } catch (const tf2::TransformException& ex) {
        RCLCPP_WARN(this->get_logger(), "Could not get robot pose: %s", ex.what());
        return false;
    }
}

void AStarROS::mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
    if (msg->data.empty()) {
        RCLCPP_WARN(this->get_logger(), "Received empty map!");
        return;
    }

    // 保存最新地图
    latest_map_ = msg;

    // 将 nav_msgs/OccupancyGrid 数据转换为 A* 的 costmap 格式
    int width = msg->info.width;
    int height = msg->info.height;
    std::vector<int8_t> costmap(msg->data.begin(), msg->data.end());

    // 配置地图参数
    AStarConfig config = astar_.getConfig();
    config.resolution = msg->info.resolution;
    config.origin_x = msg->info.origin.position.x;
    config.origin_y = msg->info.origin.position.y;
    config.map_width = width;
    config.map_height = height;
    astar_.setConfig(config);

    // 设置地图数据
    if (astar_.setMap(costmap, width, height)) {
        map_received_ = true;
        RCLCPP_INFO(this->get_logger(),
                    "Map received: %d x %d, resolution=%.3f, origin=(%.2f, %.2f)",
                    width, height, config.resolution, config.origin_x, config.origin_y);
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to set map data!");
    }
}

void AStarROS::goalCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
{
    if (!map_received_) {
        RCLCPP_WARN(this->get_logger(), "Map not received yet. Cannot plan!");
        return;
    }

    double goal_x = msg->pose.position.x;
    double goal_y = msg->pose.position.y;

    RCLCPP_INFO(this->get_logger(), "Goal received: (%.2f, %.2f)", goal_x, goal_y);

    // 通过 TF 获取机器人当前位置
    double start_x, start_y;
    if (!getRobotPose(start_x, start_y)) {
        RCLCPP_WARN(this->get_logger(), "Failed to get robot pose. Cannot plan!");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Robot pose: (%.2f, %.2f)", start_x, start_y);

    planAndPublish(start_x, start_y, goal_x, goal_y);
}

void AStarROS::planAndPublish(double start_x, double start_y,
                               double goal_x, double goal_y)
{
    RCLCPP_INFO(this->get_logger(),
                "Planning path from (%.2f, %.2f) to (%.2f, %.2f)...",
                start_x, start_y, goal_x, goal_y);

    // 执行 A* 搜索
    std::vector<std::pair<double, double>> path_points;
    bool success = astar_.plan(start_x, start_y, goal_x, goal_y, path_points);

    if (!success) {
        RCLCPP_WARN(this->get_logger(), "No path found!");
        // 发布空路径
        nav_msgs::msg::Path empty_path;
        empty_path.header.frame_id = latest_map_->header.frame_id;
        empty_path.header.stamp = this->now();
        path_pub_->publish(empty_path);
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Path found! %zu waypoints.", path_points.size());

    // 发布路径
    publishPath(path_points, goal_x, goal_y);
}

void AStarROS::publishPath(const std::vector<std::pair<double, double>>& path_points,
                            double /*goal_x*/, double /*goal_y*/)
{
    nav_msgs::msg::Path path_msg;
    path_msg.header.frame_id = latest_map_->header.frame_id;
    path_msg.header.stamp = this->now();

    for (const auto& pt : path_points) {
        geometry_msgs::msg::PoseStamped pose;
        pose.header.frame_id = latest_map_->header.frame_id;
        pose.header.stamp = this->now();
        pose.pose.position.x = pt.first;
        pose.pose.position.y = pt.second;
        pose.pose.position.z = 0.0;
        pose.pose.orientation.x = 0.0;
        pose.pose.orientation.y = 0.0;
        pose.pose.orientation.z = 0.0;
        pose.pose.orientation.w = 1.0;
        path_msg.poses.push_back(pose);
    }

    path_pub_->publish(path_msg);
    RCLCPP_DEBUG(this->get_logger(), "Published path with %zu poses.", path_msg.poses.size());
}

} // namespace planner