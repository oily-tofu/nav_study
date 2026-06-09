#include <rclcpp/rclcpp.hpp>
#include "my_costmap/inflator.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<my_costmap::Inflator>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}