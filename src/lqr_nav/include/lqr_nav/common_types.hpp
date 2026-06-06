#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <cmath>
#include <Eigen/Dense>

namespace lqr_controller
{

    struct RobotState {
        double x = 0;
        double y = 0;
        double yaw = 0;
        int hz = 10;
    };

    struct PathPoint {
        double x = 0;
        double y = 0;
        double yaw = 0;
        double v_ref = 0;
        double w_ref = 0;
        int index = 0;
    };

    struct ErrorState {
        double e_x = 0;
        double e_y = 0;
        double e_theta = 0;
    };

    // 辅助函数（内联定义，避免多文件链接冲突）
    inline double normalizeAngle(double angle)
    {
        while (angle > M_PI) angle -= 2.0 * M_PI;
        while (angle < -M_PI) angle += 2.0 * M_PI;
        return angle;
    }

    inline double distance2D(double x1, double y1, double x2, double y2)
    {
        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

} // namespace lqr_controller

#endif // COMMON_TYPES_HPP