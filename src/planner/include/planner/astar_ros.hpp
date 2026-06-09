#ifndef ASTAR_ROS_HPP
#define ASTAR_ROS_HPP

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2/time.h>

#include "planner/astar_search.hpp"

namespace planner
{

/**
 * @brief A* 路径规划器的 ROS 接口节点
 * 
 * 订阅：
 *   - /map (nav_msgs/OccupancyGrid): 占用栅格地图
 *   - /goal_pose (geometry_msgs/PoseStamped): 目标点
 * 
 * 发布：
 *   - /path (nav_msgs/Path): 规划出的路径
 */
class AStarROS : public rclcpp::Node
{
public:
    explicit AStarROS(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    ~AStarROS() = default;

private:
    /**
     * @brief 地图回调函数
     */
    void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);

    /**
     * @brief 目标点回调函数
     */
    void goalCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);

    /**
     * @brief 执行路径规划并发布路径
     * @param start_x 起点世界坐标 x
     * @param start_y 起点世界坐标 y
     * @param goal_x  目标点世界坐标 x
     * @param goal_y  目标点世界坐标 y
     */
    void planAndPublish(double start_x, double start_y,
                        double goal_x, double goal_y);

    /**
     * @brief 发布路径到 /path 话题
     * @param path_points 路径点列表（世界坐标）
     * @param goal_x 目标点 x（用于计算路径帧）
     * @param goal_y 目标点 y
     */
    void publishPath(const std::vector<std::pair<double, double>>& path_points,
                     double goal_x, double goal_y);

    /**
     * @brief 通过 TF 获取机器人当前在 map 坐标系下的位置
     * @param x 输出：x 坐标
     * @param y 输出：y 坐标
     * @return 是否成功获取
     */
    bool getRobotPose(double& x, double& y);

    // A* 搜索算法实例
    AStarSearch astar_;

    // 是否已接收到地图
    bool map_received_;

    // 最新的地图消息（保存以便获取 frame_id 等信息）
    nav_msgs::msg::OccupancyGrid::SharedPtr latest_map_;

    // TF2
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    // ROS 通信
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_sub_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
};

} // namespace planner

#endif // ASTAR_ROS_HPP