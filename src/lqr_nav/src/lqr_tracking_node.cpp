#include "lqr_nav/lqr_controller_node.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<lqr_controller::LQRControllerNode>("lqr_tracking_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}