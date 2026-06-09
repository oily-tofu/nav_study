#ifndef LQR_CONTROLLER_NODE_HPP
#define LQR_CONTROLLER_NODE_HPP

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/path.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include <tf2/utils.h>

#include "lqr_nav/common_types.hpp"
#include "lqr_nav/trajectory_manager.hpp"
#include "lqr_nav/lqr_solver.hpp"
#include "lqr_nav/performance_analyzer.hpp"

namespace lqr_controller
{

    class LQRControllerNode : public rclcpp::Node
    {
    public:
        LQRControllerNode(const std::string& name);

    private:
        // ROS2 接口
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
        rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;
        std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
        rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr path_sub_;
        rclcpp::TimerBase::SharedPtr control_timer_;

        bool is_path_received_ = false;
        bool is_robot_arrived_ = false;
        int max_reached_index_ = 0; 

        // 算法模块
        TrajectoryManager trajectory_manager_;
        LQRSolver lqr_solver_;

        // 参数
        Eigen::Matrix3d Q_;
        Eigen::Matrix2d R_;
        double dt_ = 0.1;
        double max_linear_speed_ = 0.5;
        double max_angular_speed_ = 1.0;
        int curvature_window_ = 6;

        // 性能分析器
        PerformanceAnalyzer analyzer_;

        // 方法
        void initProperties();
        void pathCallback(const nav_msgs::msg::Path::SharedPtr msg);
        void controlCallback();
        void controlCallbackTest();  // 性能测试版
        void getRobotPose(RobotState& state);

        void publishPredictionMarkers(const PathPoint& nearest);

        ErrorState computeErrorState(const RobotState& state, const PathPoint& ref);
    };

} // namespace lqr_controller

#endif // LQR_CONTROLLER_NODE_HPP