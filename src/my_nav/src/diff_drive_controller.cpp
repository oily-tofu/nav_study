#include "diff_drive_controller.hpp"
#include <iostream>

namespace diff_drive 
{

    RobotState robot_state;// sk-850b4c32f5ec4a42bbaf4175af0fb7a7

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    初始化类
    */
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    Diffinit::Diffinit(const std::string &name): Node(name) 
    {
        // 初始化发布者和订阅者
        Diffinit::initProperties();
        RCLCPP_INFO(this->get_logger(), "Diffinit initialized.");
    };
            
    void Diffinit::initProperties()
    {
        //  cmd_vel 话题
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        // 创建 TF 缓冲区
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        // 创建 TF 监听器
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
        goal_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/goal_pose", 10, std::bind(&Diffinit::goalCallback, this, std::placeholders::_1));
        // 创建控制定时器
        control_timer_ = this->create_wall_timer(std::chrono::milliseconds(1000 / robot_state.hz), std::bind(&Diffinit::controlCallback, this));
    };
    void Diffinit::goalCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
        goal_map = *msg;
        this -> is_goal_received = true;
        RCLCPP_INFO(this->get_logger(), "Received goal: (%.2f, %.2f)", goal_map.pose.position.x, goal_map.pose.position.y);
        
    };
    void Diffinit::controlCallback()
    {
        // 获取当前机器人位姿
        geometry_msgs::msg::TransformStamped map_to_base;
        try {
            map_to_base = tf_buffer_->lookupTransform("base_link", "map", tf2::TimePointZero); 
            if (!this -> is_goal_received) {
                return;
            }
            tf2::doTransform(goal_map, this -> goal_baselink, map_to_base);
            // RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500, "坐标转换完成");
            Diffinit::getGoalmsgs(this -> goal_baselink);

            if (!diff_move_.is_arrived(robot_state, cmd_vel_pub_)) {
                 diff_move_.auto_move(robot_state, cmd_vel_pub_);
                // diff_move_.pure_pursuit(robot_state, cmd_vel_pub_);
                //diff_move_.LQR_move(robot_state, cmd_vel_pub_);
            }


            
            this -> is_goal_received = !diff_move_.is_arrived(robot_state, cmd_vel_pub_);
            // RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Goal in base_link frame: (%.2f, %.2f)", goal_baselink.pose.position.x, goal_baselink.pose.position.y);
        } 
        catch (tf2::TransformException &ex) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this -> get_clock(), 2000, "Could not transform: %s", ex.what());
            return;
        }
    };

    void Diffinit::getGoalmsgs(const geometry_msgs::msg::PoseStamped &goal_baselink){
        tf2::Quaternion q(
            goal_baselink.pose.orientation.x,
            goal_baselink.pose.orientation.y,
            goal_baselink.pose.orientation.z,
            goal_baselink.pose.orientation.w
        );
        tf2::Matrix3x3 m(q);
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);
        
        robot_state.x = goal_baselink.pose.position.x;
        robot_state.y = goal_baselink.pose.position.y;
        robot_state.distance = std::sqrt(robot_state.x * robot_state.x + robot_state.y * robot_state.y);
        robot_state.angle_to_goal = std::atan2(robot_state.y, robot_state.x);
        robot_state.goal_angle = yaw;
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500, "Distance: %.2f", robot_state.distance);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    移动类
    */
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Diffmove::normalize_angle(double &angle)
    {
        while (angle > M_PI) angle -= 2.0 * M_PI;
        while (angle < -M_PI) angle += 2.0 * M_PI;
    }
    
    void Diffmove::move_base(double vx, double vw, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub)
    {
        geometry_msgs::msg::Twist cmd_vel_msg;
        cmd_vel_msg.linear.x = vx;
        cmd_vel_msg.angular.z = vw;
        cmd_vel_pub->publish(cmd_vel_msg);
    }

    void Diffmove::move_stop(const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub)
    {
        geometry_msgs::msg::Twist cmd_vel_msg;
        cmd_vel_msg.linear.x = 0.0;
        cmd_vel_msg.angular.z = 0.0;
        cmd_vel_pub->publish(cmd_vel_msg);
    }

    void Diffmove::auto_move(const RobotState robot_state, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub)
    {
        double angle_diff;
        double vx = 1 * robot_state.x; // 线速度与距离成正比
        double vw = 0.0; // 初始角速度为0
        if (std::abs(robot_state.distance) < 0.1) {
            angle_diff = robot_state.goal_angle;
            Diffmove::normalize_angle(angle_diff);
            vw = 1.0 * angle_diff; 
            vx = std::min(std::max(vx, 0.1), 0.3);
            Diffmove::move_base(0.0, vw, cmd_vel_pub);
            std::cout << "对其目标中： " << "distance: " << robot_state.distance << " vw: " << vw << std::endl;
        }
        else{
            angle_diff = robot_state.angle_to_goal;
            Diffmove::normalize_angle(angle_diff);
            vw = 1.0 * angle_diff; 
            // 限制最大速度
            vx = std::min(std::max(vx, 0.1), 0.3);
            vw = std::min(std::max(vw, -1.0), 1.0);
            Diffmove::move_base(vx, vw, cmd_vel_pub);
            std::cout << "正常行驶中： " << "vx: " << vx << " vw: " << vw << std::endl;
        }
        
    }

    bool Diffmove::is_arrived(const RobotState robot_state, rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub)
    {
        if (std::abs(robot_state.goal_angle) < 0.15 && std::abs(robot_state.distance) < 0.15) {
            std::cout << "Arrived at goal!" << std::endl;
            Diffmove::move_stop(cmd_vel_pub);
            return true;
        }
        return false;
    }

    void Diffmove::pure_pursuit(const RobotState robot_state, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub)
    {
        // 纯跟踪算法实现
        double angle_to_goal = std::atan2(robot_state.y, robot_state.x);
        double r;
        if (std::fabs(robot_state.y) < 0.01) {
            r = 100;  // 直线行驶
        } else {
            r = (robot_state.distance * robot_state.distance) / (2.0 * robot_state.y);
        }
        
        double vx = 1 * robot_state.distance; 
        double vw = vx / r; // 角速度与角度差成正比
        
        // 限制最大速度
        vx = std::min(std::max(vx, 0.1), 0.3);
        vw = std::min(std::max(vw, -1.0), 1.0);
        
        Diffmove::move_base(vx, vw, cmd_vel_pub);
    }

    void Diffmove::LQR_move(const RobotState robot_state, const rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr &cmd_vel_pub)
    {

        Eigen::MatrixXd A(3,3); // 状态转移矩阵
        Eigen::MatrixXd B(3,2); // 控制输入矩阵
        Eigen::MatrixXd Q(3, 3); // 状态权重矩阵
        Eigen::MatrixXd R(2, 2); // 控制输入权重矩阵

        double v = 0.3; // 线速度与距离成正比
        double T_time = 1.0 / robot_state.hz;
        double cos_theta = std::cos(robot_state.angle_to_goal);
        double sin_theta = std::sin(robot_state.angle_to_goal);

        
        A << 1, 0, -v*sin_theta * T_time,
             0, 1, v*cos_theta * T_time,
             0, 0, 1;
        B << T_time * cos_theta, -v * sin_theta * T_time * T_time / 2,
             T_time * sin_theta, v * cos_theta * T_time * T_time / 2,
             0, T_time;

        Q << 1, 0, 0,
             0, 1, 0,
             0, 0, 5;
        R << 0.1, 0,
             0, 5;
        
        // 求解 Riccati 方程得到 K 矩阵
        Eigen::MatrixXd K = solveLQR(A, B, Q, R);
        
        // 计算控制输入 u = -K * x
        Eigen::VectorXd x(3); // 系统状态向量
        x << robot_state.x, robot_state.y, robot_state.angle_to_goal; // 示例状态向量
        
        Eigen::VectorXd u = K * x; // 控制输入
        
        v = u(0); // 线速度
        double vw = u(1); // 角速度
        
        // 限制最大速度
        v = std::min(std::max(v, 0.0), 0.3);
        vw = std::min(std::max(vw, -1.0), 1.0);
        
        Diffmove::move_base(v, vw, cmd_vel_pub);
    }

    Eigen::MatrixXd Diffmove::solveLQR(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R,int max_iter, double eps) {
    int n = A.rows();
    
    Eigen::MatrixXd P = Q;
    Eigen::MatrixXd P_next;
    
    for (int i = 0; i < max_iter; ++i) {
        // P = A^T P A - A^T P B (R + B^T P B)^{-1} B^T P A + Q
        Eigen::MatrixXd tmp = B.transpose() * P * B + R;
        Eigen::MatrixXd K = tmp.inverse() * (B.transpose() * P * A);
        P_next = A.transpose() * P * (A - B * K) + Q;
        
        // 检查收敛
        if ((P_next - P).norm() < eps) {
            P = P_next;
            break;
        }
        P = P_next;
    }
    
    // 计算最终的 K
    Eigen::MatrixXd K = (R + B.transpose() * P * B).inverse() * (B.transpose() * P * A);
    return K;
    }
};
     


