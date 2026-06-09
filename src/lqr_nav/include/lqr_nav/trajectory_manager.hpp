#ifndef TRAJECTORY_MANAGER_HPP
#define TRAJECTORY_MANAGER_HPP

#include <vector>
#include <algorithm>
#include "nav_msgs/msg/path.hpp"
#include "lqr_nav/common_types.hpp"

// 轨迹管理器类，用于管理 LQR 控制器的轨迹

namespace lqr_controller
{

    class TrajectoryManager
    {
    public:
        TrajectoryManager() = default;

        void setPath(const nav_msgs::msg::Path& path);
        void setCurvatureWindow(int window);

        PathPoint findNearestPoint(double robot_x, double robot_y) const;
        PathPoint getReferencePoint(const PathPoint& nearest, double max_speed, double* out_lookahead_dist = nullptr) const;

        int getPathSize() const { return static_cast<int>(path_.poses.size()); }
        bool isPathValid() const { return path_.poses.size() >= 2; }


        const nav_msgs::msg::Path& getPath() const { return path_; }

    private:
        nav_msgs::msg::Path path_;
        int curvature_window_ = 6;

        double calcPathYaw(int idx) const;
        double calcPathCurvature(int idx) const;
    };

} // namespace lqr_controller

#endif // TRAJECTORY_MANAGER_HPP