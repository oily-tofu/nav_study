#ifndef LQR_SOLVER_HPP
#define LQR_SOLVER_HPP

#include <Eigen/Dense>

namespace lqr_controller
{

    class LQRSolver
    {
    public:
        LQRSolver() = default;

        void setDt(double dt) { dt_ = dt; }
        void setWeights(const Eigen::Matrix3d& Q, const Eigen::Matrix2d& R);

        Eigen::Matrix<double, 2, 3> solve(const Eigen::Matrix3d& A,
                                           const Eigen::Matrix<double, 3, 2>& B,
                                           int max_iter = 1000,
                                           double eps = 1e-6) const;

        const Eigen::Matrix3d& getQ() const { return Q_; }
        const Eigen::Matrix2d& getR() const { return R_; }

    private:
        double dt_ = 0.1;
        Eigen::Matrix3d Q_ = Eigen::Matrix3d::Identity();
        Eigen::Matrix2d R_ = Eigen::Matrix2d::Identity();
    };

} // namespace lqr_controller

#endif // LQR_SOLVER_HPP