#include "lqr_nav/trajectory_manager.hpp"

namespace lqr_controller
{

    void TrajectoryManager::setPath(const nav_msgs::msg::Path& path)
    {
        path_ = path;
        is_closed_loop_ = false;

        if (path_.poses.size() >= 3) {
            double dist = distance2D(
                path_.poses[0].pose.position.x, path_.poses[0].pose.position.y,
                path_.poses.back().pose.position.x, path_.poses.back().pose.position.y);
            is_closed_loop_ = (dist < 0.2);
        }
    }

    void TrajectoryManager::setCurvatureWindow(int window)
    {
        curvature_window_ = std::max(1, window);
    }

    double TrajectoryManager::calcPathYaw(int idx) const
    {
        if (idx < 0 || idx >= static_cast<int>(path_.poses.size()) - 1) {
            return 0.0;
        }
        double dx = path_.poses[idx + 1].pose.position.x - path_.poses[idx].pose.position.x;
        double dy = path_.poses[idx + 1].pose.position.y - path_.poses[idx].pose.position.y;
        return std::atan2(dy, dx);
    }

    double TrajectoryManager::calcPathCurvature(int idx) const
    {
        int total = static_cast<int>(path_.poses.size());
        if (idx < 0 || idx >= total || total < 3) return 0.0;

        std::vector<double> curvatures;
        int start = idx;
        int end = std::min(total - 2, idx + curvature_window_ - 1);

        for (int i = start; i <= end; ++i) {
            double dx = path_.poses[i + 1].pose.position.x - path_.poses[i].pose.position.x;
            double dy = path_.poses[i + 1].pose.position.y - path_.poses[i].pose.position.y;
            double ds = std::sqrt(dx * dx + dy * dy);
            if (ds < 1e-6) continue;

            double dx_prev = path_.poses[i].pose.position.x - path_.poses[i - 1].pose.position.x;
            double dy_prev = path_.poses[i].pose.position.y - path_.poses[i - 1].pose.position.y;
            double ds_prev = std::sqrt(dx_prev * dx_prev + dy_prev * dy_prev);
            if (ds_prev < 1e-6) continue;

            double yaw1 = std::atan2(dy_prev, dx_prev);
            double yaw2 = std::atan2(dy, dx);
            double dyaw = normalizeAngle(yaw2 - yaw1);

            curvatures.push_back(std::abs(dyaw) / ds);
        }

        if (curvatures.empty()) return 0.0;

        std::sort(curvatures.begin(), curvatures.end());
        double sum = 0.0;
        int count = 0;
        int vs = (curvatures.size() >= 3) ? 1 : 0;
        int ve = (curvatures.size() >= 3) ? static_cast<int>(curvatures.size()) - 1 : static_cast<int>(curvatures.size());

        for (int i = vs; i < ve; ++i) { sum += curvatures[i]; count++; }
        return (count > 0) ? (sum / count) : 0.0;
    }

    PathPoint TrajectoryManager::findNearestPoint(double robot_x, double robot_y) const
    {
        PathPoint result;
        if (path_.poses.empty()) return result;

        double min_dist = std::numeric_limits<double>::max();
        int nearest_idx = 0;

        for (size_t i = 0; i < path_.poses.size(); ++i) {
            double d = distance2D(robot_x, robot_y,
                                  path_.poses[i].pose.position.x,
                                  path_.poses[i].pose.position.y);
            if (d < min_dist) {
                min_dist = d;
                nearest_idx = static_cast<int>(i);
            }
        }

        result.x = path_.poses[nearest_idx].pose.position.x;
        result.y = path_.poses[nearest_idx].pose.position.y;
        result.yaw = calcPathYaw(nearest_idx);
        result.index = nearest_idx;
        return result;
    }

    PathPoint TrajectoryManager::getReferencePoint(const PathPoint& nearest, double max_speed, double* out_lookahead_dist) const
    {
        PathPoint ref = nearest;
        int total = static_cast<int>(path_.poses.size());
        int look_step = std::max(1, curvature_window_);
        int look_idx = std::min(nearest.index + look_step, total - 2);

        // 计算前视距离
        double actual_dist = 0.0;
        for (int i = nearest.index; i < look_idx; ++i) {
            actual_dist += distance2D(
                path_.poses[i].pose.position.x, path_.poses[i].pose.position.y,
                path_.poses[i + 1].pose.position.x, path_.poses[i + 1].pose.position.y);
        }
        if (out_lookahead_dist) *out_lookahead_dist = actual_dist;

        ref.x = path_.poses[look_idx].pose.position.x;
        ref.y = path_.poses[look_idx].pose.position.y;
        ref.yaw = calcPathYaw(look_idx);
        ref.index = look_idx;

        // 参考速度 = f(曲率)
        double curvature = std::abs(calcPathCurvature(look_idx));
        double max_curvature = 5.0;
        double speed_scale = 1.0 - std::min(curvature / max_curvature, 0.8);
        ref.v_ref = max_speed * std::max(speed_scale, 0.2);

        // 参考角速度
        ref.w_ref = ref.v_ref * curvature;
        double dyaw = calcPathYaw(look_idx) - calcPathYaw(std::max(0, look_idx - 1));
        dyaw = normalizeAngle(dyaw);
        if (dyaw < 0) ref.w_ref = -ref.w_ref;

        return ref;
    }

} // namespace lqr_controller