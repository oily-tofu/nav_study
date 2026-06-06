#ifndef DIFF_DRIVE_CONTROLLER_HPP
#define DIFF_DRIVE_CONTROLLER_HPP

#include <cmath>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>


#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <tf2/LinearMath/Quaternion.h>

#include <Eigen/Dense>
#include <Eigen/Core>

namespace diff_drive 
{

    struct RobotState {
        double x = 0;
        double y = 0;
        double distance = 0;
        double angle_to_goal = 0;
        double goal_angle = 0;
        int hz = 10;
    };
    extern RobotState robot_state;

    class Diffmove
    {
        public: 
            void normalize_angle(double &angle);
            void move_base(double vx, double vw, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub);
            void move_stop(const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub);
            void auto_move(const RobotState robot_state, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub);
            bool is_arrived(const RobotState robot_state, rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub);
            void pure_pursuit(const RobotState robot_state, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub);
            void LQR_move(const RobotState robot_state, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub);
            Eigen::MatrixXd solveLQR(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R,int max_iter = 1000, double eps = 1e-6);
     };

    class Diffinit : public rclcpp::Node
    {
        public:

            Diffinit(const std::string &name);
        
        protected:

            rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;

            std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
            std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
            rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_sub_;
            geometry_msgs::msg::PoseStamped goal_map;

            rclcpp::TimerBase::SharedPtr control_timer_;
            geometry_msgs::msg::PoseStamped goal_baselink;

            bool is_goal_received = false;

            Diffmove diff_move_;

            void initProperties();
            void goalCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
            void controlCallback();
            void getGoalmsgs(const geometry_msgs::msg::PoseStamped &goal_baselink);
    };

    
}


#endif