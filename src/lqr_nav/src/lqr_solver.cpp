#include "lqr_nav/lqr_solver.hpp"

namespace lqr_controller
{

    void LQRSolver::setWeights(const Eigen::Matrix3d& Q, const Eigen::Matrix2d& R)
    {
        Q_ = Q;
        R_ = R;
    }

    Eigen::Matrix<double, 2, 3> LQRSolver::solve(
        const Eigen::Matrix3d& A,
        const Eigen::Matrix<double, 3, 2>& B,
        int max_iter,
        double eps) const
    {
        // 离散化 (一阶近似)
        Eigen::Matrix3d A_d = Eigen::Matrix3d::Identity() + A * dt_;
        Eigen::Matrix<double, 3, 2> B_d = B * dt_;

        // 迭代求解离散代数Riccati方程
        Eigen::Matrix3d P = Q_;

        for (int i = 0; i < max_iter; ++i) {
            Eigen::Matrix2d tmp = R_ + B_d.transpose() * P * B_d;
            Eigen::Matrix<double, 2, 3> K = tmp.inverse() * (B_d.transpose() * P * A_d);
            Eigen::Matrix3d P_next = A_d.transpose() * P * (A_d - B_d * K) + Q_;

            if ((P_next - P).norm() < eps) {
                P = P_next;
                break;
            }
            P = P_next;
        }

        Eigen::Matrix2d tmp = R_ + B_d.transpose() * P * B_d;
        Eigen::Matrix<double, 2, 3> K = tmp.inverse() * (B_d.transpose() * P * A_d);
        return K;
    }

} // namespace lqr_controller