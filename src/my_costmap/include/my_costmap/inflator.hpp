#ifndef INFLATOR_HPP
#define INFLATOR_HPP

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

namespace my_costmap
{

/**
 * @brief 地图膨胀节点
 * 
 * 订阅 /map (nav_msgs/OccupancyGrid)
 * 发布 /inflated_map (nav_msgs/OccupancyGrid)
 * 
 * 将障碍物区域向外膨胀指定半径（12cm）
 */
class Inflator : public rclcpp::Node
{
public:
    explicit Inflator(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    ~Inflator() = default;

private:
    /**
     * @brief 地图回调，执行膨胀并发布
     */
    void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);

    /**
     * @brief 执行形态学膨胀
     * @param input_costmap  输入地图数据
     * @param width          地图宽度
     * @param height         地图高度
     * @param inflation_radius 膨胀半径（像素）
     * @return 膨胀后的地图数据
     */
    std::vector<int8_t> inflateMap(const std::vector<int8_t>& input_costmap,
                                    int width, int height,
                                    int inflation_radius);

    /**
     * @brief 使用 BFS 逐层膨胀
     * @param input_costmap  输入地图数据
     * @param width          地图宽度
     * @param height         地图高度
     * @param inflation_radius 膨胀半径（像素）
     * @return 膨胀后的地图数据
     */
    std::vector<int8_t> inflateByBFS(const std::vector<int8_t>& input_costmap,
                                      int width, int height,
                                      int inflation_radius);

    // ROS 通信
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
    rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr inflated_map_pub_;

    // 参数
    double inflation_radius_;  // 膨胀半径（米）
};

} // namespace my_costmap

#endif // INFLATOR_HPP