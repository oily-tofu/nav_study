#include "my_costmap/inflator.hpp"
#include <string>
#include <memory>
#include <cmath>

namespace my_costmap
{

// 4 连通方向的偏移
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};

Inflator::Inflator(const rclcpp::NodeOptions& options)
    : Node("inflator", options)
{
    // 声明参数：膨胀半径（米）
    this->declare_parameter<double>("inflation_radius", 0.16);
    inflation_radius_ = this->get_parameter("inflation_radius").as_double();

    // 创建订阅（使用 transient_local QoS 以接收最新地图）
    map_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
        "/map", rclcpp::QoS(1).transient_local(),
        std::bind(&Inflator::mapCallback, this, std::placeholders::_1));

    // 创建发布
    inflated_map_pub_ = this->create_publisher<nav_msgs::msg::OccupancyGrid>(
        "/inflated_map", rclcpp::QoS(1).transient_local());

    RCLCPP_INFO(this->get_logger(), "Map inflator initialized.");
    RCLCPP_INFO(this->get_logger(), "  inflation_radius: %.3f m", inflation_radius_);
}

void Inflator::mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
    if (msg->data.empty()) {
        RCLCPP_WARN(this->get_logger(), "Received empty map!");
        return;
    }

    int width = msg->info.width;
    int height = msg->info.height;
    double resolution = msg->info.resolution;

    // 计算膨胀半径（像素），ceil 确保至少 1 个像素
    int inflation_radius_px = std::max(1, static_cast<int>(std::ceil(inflation_radius_ / resolution)));

    RCLCPP_INFO(this->get_logger(),
                "Inflating map: %d x %d, resolution=%.3f, radius=%d px (%.3f m)",
                width, height, resolution, inflation_radius_px, inflation_radius_);

    // 执行膨胀
    std::vector<int8_t> inflated_data = inflateByBFS(
        std::vector<int8_t>(msg->data.begin(), msg->data.end()),
        width, height, inflation_radius_px);

    // 发布膨胀后的地图
    auto out_msg = std::make_shared<nav_msgs::msg::OccupancyGrid>();
    out_msg->header = msg->header;
    out_msg->header.stamp = this->now();
    out_msg->info = msg->info;
    out_msg->data = inflated_data;

    inflated_map_pub_->publish(*out_msg);

    RCLCPP_INFO(this->get_logger(), "Inflated map published to /inflated_map");
}

std::vector<int8_t> Inflator::inflateByBFS(const std::vector<int8_t>& input_costmap,
                                             int width, int height,
                                             int inflation_radius)
{
    // 复制输入地图作为输出
    std::vector<int8_t> output = input_costmap;
    int total = width * height;

    // 距离数组：记录每个栅格到最近障碍物的距离
    // -1 表示尚未计算
    std::vector<int> distance(total, -1);

    // BFS 队列
    std::queue<int> q;

    // 1. 将所有障碍物栅格入队，距离设为 0
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            // 障碍物（occupied_thresh > 0.65, 即 >= 65）
            if (input_costmap[idx] >= 65) {
                distance[idx] = 0;
                q.push(idx);
            }
        }
    }

    // 2. BFS 逐层计算距离
    while (!q.empty()) {
        int cur_idx = q.front();
        q.pop();

        int cur_dist = distance[cur_idx];
        // 如果已达到膨胀半径，停止扩展
        if (cur_dist >= inflation_radius) {
            continue;
        }

        int cx = cur_idx % width;
        int cy = cur_idx / width;

        // 扩展 4 连通邻居
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx4[dir];
            int ny = cy + dy4[dir];

            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                continue;
            }

            int nidx = ny * width + nx;

            // 如果还未访问过（距离仍为 -1）
            if (distance[nidx] == -1) {
                distance[nidx] = cur_dist + 1;
                // 将自由空间或未知区域标记为障碍物
                if (output[nidx] < 65) {
                    output[nidx] = 100;
                }
                q.push(nidx);
            }
        }
    }

    long cells_affected = std::count_if(output.begin(), output.end(),
                                         [](int8_t v) { return v >= 65; }) -
                          std::count_if(input_costmap.begin(), input_costmap.end(),
                                        [](int8_t v) { return v >= 65; });
    RCLCPP_DEBUG(this->get_logger(), "BFS inflation complete. %ld cells affected.",
                 cells_affected);

    return output;
}

std::vector<int8_t> Inflator::inflateMap(const std::vector<int8_t>& input_costmap,
                                          int width, int height,
                                          int inflation_radius)
{
    // 兼容接口：直接调用 BFS 方法
    return inflateByBFS(input_costmap, width, height, inflation_radius);
}

} // namespace my_costmap
