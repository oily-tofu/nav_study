#include "lqr_nav/lqr_controller_node.hpp"

namespace lqr_controller
{

    LQRControllerNode::LQRControllerNode(const std::string& name)
        : Node(name)
    {
        initProperties();
        RCLCPP_INFO(this->get_logger(), "LQRControllerNode initialized.");
        RCLCPP_INFO(this->get_logger(), "Waiting for path on /path topic...");
    }

    void LQRControllerNode::initProperties()
    {
        // 声明参数
        this->declare_parameter<double>("dt", 0.1);
        this->declare_parameter<double>("max_linear_speed", 0.3);
        this->declare_parameter<double>("max_angular_speed", 1.0);
        this->declare_parameter<double>("Q_xx", 1.5);
        this->declare_parameter<double>("Q_yy", 2.5);
        this->declare_parameter<double>("Q_tt", 2.5);
        this->declare_parameter<double>("R_v", 1.0);
        this->declare_parameter<double>("R_w", 1.0);
        this->declare_parameter<int>("curvature_window", 6);

        // 读取参数
        dt_ = this->get_parameter("dt").as_double();
        max_linear_speed_ = this->get_parameter("max_linear_speed").as_double();
        max_angular_speed_ = this->get_parameter("max_angular_speed").as_double();
        curvature_window_ = this->get_parameter("curvature_window").as_int();

        double q_xx = this->get_parameter("Q_xx").as_double();
        double q_yy = this->get_parameter("Q_yy").as_double();
        double q_tt = this->get_parameter("Q_tt").as_double();
        double r_v = this->get_parameter("R_v").as_double();
        double r_w = this->get_parameter("R_w").as_double();

        Q_ << q_xx, 0, 0,
              0, q_yy, 0,
              0, 0, q_tt;
        R_ << r_v, 0,
              0, r_w;

        // 配置算法模块
        trajectory_manager_.setCurvatureWindow(curvature_window_);
        lqr_solver_.setDt(dt_);
        lqr_solver_.setWeights(Q_, R_);

        // ROS2 接口
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("/prediction_markers", 10);

        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        path_sub_ = this->create_subscription<nav_msgs::msg::Path>(
            "/path", 10, std::bind(&LQRControllerNode::pathCallback, this, std::placeholders::_1));

        // 实际控制用 controlCallback, 性能测试用 controlCallbackTest (手动切换)
        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(static_cast<int>(1000.0 / 10)),
            std::bind(&LQRControllerNode::controlCallback, this));
    }

    void LQRControllerNode::pathCallback(const nav_msgs::msg::Path::SharedPtr msg)
    {
        trajectory_manager_.setPath(*msg);
        RCLCPP_INFO(this->get_logger(), "Path received with %zu poses.", msg->poses.size());
        is_path_received_ = true;
        is_robot_arrived_ = false;
        max_reached_index_ = 0;
    }

    void LQRControllerNode::getRobotPose(RobotState& state)
    {
        try {
            auto transform = tf_buffer_->lookupTransform("map", "base_link", tf2::TimePointZero);
            state.x = transform.transform.translation.x;
            state.y = transform.transform.translation.y;
            auto& q = transform.transform.rotation;
            double siny_cosp = 2.0 * (q.w * q.z + q.x * q.y);
            double cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z);
            state.yaw = std::atan2(siny_cosp, cosy_cosp);
        } catch (tf2::TransformException& ex) {
            RCLCPP_WARN(this->get_logger(), "Could not get robot pose: %s", ex.what());
        }
    }

    ErrorState LQRControllerNode::computeErrorState(const RobotState& state, const PathPoint& ref)
    {
        ErrorState err;
        double dx = state.x - ref.x;
        double dy = state.y - ref.y;
        double ct = std::cos(ref.yaw);
        double st = std::sin(ref.yaw);

        err.e_x = dx * ct + dy * st;
        err.e_y = -dx * st + dy * ct;
        err.e_theta = normalizeAngle(state.yaw - ref.yaw);
        return err;
    }

    void LQRControllerNode::publishPredictionMarkers(const PathPoint& nearest)
    {
        const auto& path = trajectory_manager_.getPath();
        if (path.poses.size() < 2) return;

        visualization_msgs::msg::MarkerArray markers;

        // 清空旧标记
        visualization_msgs::msg::Marker clear_marker;
        clear_marker.header.frame_id = "map";
        clear_marker.header.stamp = this->now();
        clear_marker.action = visualization_msgs::msg::Marker::DELETEALL;
        markers.markers.push_back(clear_marker);

        // 最近点（红色）
        visualization_msgs::msg::Marker nm;
        nm.header.frame_id = "map";
        nm.header.stamp = this->now();
        nm.ns = "nearest_point";
        nm.id = 0;
        nm.type = visualization_msgs::msg::Marker::SPHERE;
        nm.action = visualization_msgs::msg::Marker::ADD;
        nm.pose.position.x = nearest.x;
        nm.pose.position.y = nearest.y;
        nm.pose.position.z = 0.05;
        nm.pose.orientation.w = 1.0;
        nm.scale.x = nm.scale.y = nm.scale.z = 0.15;
        nm.color.a = 1.0; nm.color.r = 1.0; nm.color.g = 0.0; nm.color.b = 0.0;
        markers.markers.push_back(nm);

        // 前视路径点（绿色）
        for (int i = 0; i < curvature_window_; ++i) {
            int idx = nearest.index + i + 1;
            if (idx >= static_cast<int>(path.poses.size())) break;

            visualization_msgs::msg::Marker lm;
            lm.header.frame_id = "map";
            lm.header.stamp = this->now();
            lm.ns = "lookahead_points";
            lm.id = i;
            lm.type = visualization_msgs::msg::Marker::SPHERE;
            lm.action = visualization_msgs::msg::Marker::ADD;
            lm.pose.position.x = path.poses[idx].pose.position.x;
            lm.pose.position.y = path.poses[idx].pose.position.y;
            lm.pose.position.z = 0.03;
            lm.pose.orientation.w = 1.0;
            lm.scale.x = lm.scale.y = lm.scale.z = 0.08;
            lm.color.a = 0.8; lm.color.r = 0.0; lm.color.g = 1.0; lm.color.b = 0.0;
            markers.markers.push_back(lm);
        }

        marker_pub_->publish(markers);
    }

    void LQRControllerNode::controlCallback()
    {
        if (!is_path_received_) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Path not received yet.");
            return;
        }

        if (!trajectory_manager_.isPathValid()) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Path has less than 2 poses.");
            return;
        }

        if (is_robot_arrived_) return;

        // 1. 获取机器人位姿
        RobotState state;
        getRobotPose(state);

        // 2. 找最近点
        PathPoint nearest = trajectory_manager_.findNearestPoint(state.x, state.y);

        

        // 3. 更新进度
        if (nearest.index > max_reached_index_) {
            max_reached_index_ = nearest.index;
        }

        // 4. 获取参考点
        double lookahead_dist = 0.0;
        PathPoint ref = trajectory_manager_.getReferencePoint(nearest, max_linear_speed_, &lookahead_dist);

        // 5. 检查终点
        const auto& path = trajectory_manager_.getPath();
        double dist_to_goal = distance2D(state.x, state.y,
                                          path.poses.back().pose.position.x,
                                          path.poses.back().pose.position.y);

        if (dist_to_goal < 0.3) {
            geometry_msgs::msg::Twist stop;
            stop.linear.x = 0.0; stop.angular.z = 0.0;
            cmd_vel_pub_->publish(stop);
            RCLCPP_INFO_ONCE(this->get_logger(), "Goal reached! Distance: %.2f m", dist_to_goal);
            is_robot_arrived_ = true;
            is_path_received_ = false;
            return;
        }

        // 6. 计算误差状态
        ErrorState err = computeErrorState(state, ref);

        // 7. 构建系统矩阵
        Eigen::Matrix3d A_c;
        A_c << 0,         ref.w_ref, 0,
               -ref.w_ref, 0,        ref.v_ref,
               0,          0,        0;

        Eigen::Matrix<double, 3, 2> B_c;
        B_c << 1, 0,
               0, 0,
               0, 1;

        // 8. 求解LQR
        auto K = lqr_solver_.solve(A_c, B_c);

        // 9. 计算控制量
        Eigen::Vector3d e_vec;
        e_vec << err.e_x, err.e_y, err.e_theta;
        Eigen::Vector2d u = -K * e_vec;

        double v_cmd = ref.v_ref + u(0);
        double w_cmd = ref.w_ref + u(1);

        v_cmd = std::max(0.0, std::min(v_cmd, max_linear_speed_));
        w_cmd = std::max(-max_angular_speed_, std::min(w_cmd, max_angular_speed_));

        // 10. 发布cmd_vel
        geometry_msgs::msg::Twist cmd;
        cmd.linear.x = v_cmd;
        cmd.angular.z = w_cmd;
        cmd_vel_pub_->publish(cmd);

        // 11. 可视化
        publishPredictionMarkers(nearest);

        // 12. 打印前视距离（变化时）
        static double last_lookahead = 0.0;
        if (std::abs(lookahead_dist - last_lookahead) > 0.01) {
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                "Lookahead: %d points, %.2f m (curvature_window=%d)",
                curvature_window_, lookahead_dist, curvature_window_);
            last_lookahead = lookahead_dist;
        }

        RCLCPP_DEBUG(this->get_logger(),
            "e_x=%.3f e_y=%.3f e_theta=%.3f | v_ref=%.3f w_ref=%.3f | v_cmd=%.3f w_cmd=%.3f",
            err.e_x, err.e_y, err.e_theta, ref.v_ref, ref.w_ref, v_cmd, w_cmd);
    }

    // ========== 性能测试版控制回调 ==========
    // void LQRControllerNode::controlCallbackTest()
    // {
    //     if (!is_path_received_) {
    //         RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Path not received yet.");
    //         return;
    //     }

    //     if (!trajectory_manager_.isPathValid()) return;

    //     // 首次运行时初始化测试
    //     if (!analyzer_.isTesting() && analyzer_.getTestsDone() == 0) {
    //         // 设置 ρ 遍历范围
    //         analyzer_.setRhoValues({0.1, 0.5, 1.0, 1.5, 2.0, 3.0, 5.0, 10.0});
    //         analyzer_.setQNominal(Q_);
    //         // 开始第一个测试
    //         double rho = analyzer_.getNextRho();
    //         analyzer_.beginTest(rho);
    //         is_robot_arrived_ = false;
    //         max_reached_index_ = 0;
    //         RCLCPP_INFO(this->get_logger(), "========== Test %d/%d: ρ = %.2f ==========",
    //             analyzer_.getTestsDone() + 1, analyzer_.getTestsTotal(), rho);
    //     }

    //     if (!analyzer_.isTesting()) return;
    //     if (is_robot_arrived_) return;

    //     // 1. 获取位姿
    //     RobotState state;
    //     getRobotPose(state);

    //     // 2. 最近点
    //     PathPoint nearest = trajectory_manager_.findNearestPoint(state.x, state.y);
    //     if (nearest.index > max_reached_index_) max_reached_index_ = nearest.index;

    //     // 3. 参考点
    //     double lookahead_dist = 0.0;
    //     PathPoint ref = trajectory_manager_.getReferencePoint(nearest, max_linear_speed_, &lookahead_dist);

    //     // 4. 检查终点
    //     const auto& path = trajectory_manager_.getPath();
    //     int last_idx = static_cast<int>(path.poses.size()) - 1;
    //     double dist_to_goal = distance2D(state.x, state.y,
    //                                       path.poses[last_idx].pose.position.x,
    //                                       path.poses[last_idx].pose.position.y);
    //     bool near_last = (nearest.index >= last_idx - 1);


    //     // 到达终点 → 结束本次测试
    //     if (near_last && dist_to_goal < 0.2) {
    //         geometry_msgs::msg::Twist stop;
    //         stop.linear.x = 0.0; stop.angular.z = 0.0;
    //         cmd_vel_pub_->publish(stop);
            
    //         analyzer_.endTest();
    //         is_robot_arrived_ = true;
    //         is_path_received_ = false;

    //         RCLCPP_INFO(this->get_logger(), "Test ρ=%.2f done. RMSE_e_y=%.4f, Max_e_y=%.4f",
    //             analyzer_.getCurrentRho(),
    //             analyzer_.getResults().back().rmse_e_y,
    //             analyzer_.getResults().back().max_e_y);

    //         // 还有下一个 ρ？
    //         if (!analyzer_.allTestsDone()) {
    //             double next_rho = analyzer_.getNextRho();
    //             analyzer_.beginTest(next_rho);
    //             is_robot_arrived_ = false;
    //             max_reached_index_ = 0;
    //             RCLCPP_INFO(this->get_logger(), "========== Test %d/%d: ρ = %.2f ==========",
    //                 analyzer_.getTestsDone() + 1, analyzer_.getTestsTotal(), next_rho);
    //         } else {
    //             analyzer_.printReport();
    //             rclcpp::shutdown();
    //         }
    //         return;
    //     }

    //     // 5. 计算误差 — 使用缩放后的 Q 矩阵
    //     ErrorState err = computeErrorState(state, ref);
    //     analyzer_.record(err.e_y, err.e_theta);

    //     // 6. 用缩放后的 Q 求解 LQR
    //     auto scaled_Q = analyzer_.getScaledQ();
    //     lqr_solver_.setWeights(scaled_Q, R_);

    //     Eigen::Matrix3d A_c;
    //     A_c << 0, ref.w_ref, 0, -ref.w_ref, 0, ref.v_ref, 0, 0, 0;
    //     Eigen::Matrix<double, 3, 2> B_c;
    //     B_c << 1, 0, 0, 0, 0, 1;
    //     auto K = lqr_solver_.solve(A_c, B_c);

    //     Eigen::Vector3d e_vec;
    //     e_vec << err.e_x, err.e_y, err.e_theta;
    //     Eigen::Vector2d u = -K * e_vec;

    //     double v_cmd = ref.v_ref + u(0);
    //     double w_cmd = ref.w_ref + u(1);
    //     v_cmd = std::max(0.0, std::min(v_cmd, max_linear_speed_));
    //     w_cmd = std::max(-max_angular_speed_, std::min(w_cmd, max_angular_speed_));

    //     geometry_msgs::msg::Twist cmd;
    //     cmd.linear.x = v_cmd; cmd.angular.z = w_cmd;
    //     cmd_vel_pub_->publish(cmd);
    //     publishPredictionMarkers(nearest);
    // }

} // namespace lqr_controller
