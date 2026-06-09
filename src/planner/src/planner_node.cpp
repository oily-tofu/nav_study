#include <rclcpp/rclcpp.hpp>
#include "planner/astar_ros.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<planner::AStarROS>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}