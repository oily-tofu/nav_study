#ifndef PERFORMANCE_ANALYZER_HPP
#define PERFORMANCE_ANALYZER_HPP

#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <Eigen/Dense>

// 性能分析器类，用于分析 LQR 控制器的性能

namespace lqr_controller
{

    struct PerformanceResult {
        double rho = 0.0;
        double rmse_e_y = 0.0;
        double max_e_y = 0.0;
        double rmse_e_theta = 0.0;
        double completion_time = 0.0;
        bool is_best_rmse = false;
        bool is_best_max = false;
    };

    class PerformanceAnalyzer
    {
    public:
        PerformanceAnalyzer() = default;

        void setRhoValues(const std::vector<double>& rhos) { rho_values_ = rhos; }
        void setQNominal(const Eigen::Matrix3d& Q) { Q_nominal_ = Q; }

        void beginTest(double rho);
        void record(double e_y, double e_theta);
        void endTest();

        void printReport() const;

        bool allTestsDone() const { return current_index_ >= static_cast<int>(rho_values_.size()); }
        double getCurrentRho() const { return current_rho_; }
        Eigen::Matrix3d getScaledQ() const { return current_rho_ * Q_nominal_; }
        bool isTesting() const { return is_testing_; }
        double getNextRho() const;
        int getTestsTotal() const { return static_cast<int>(rho_values_.size()); }
        int getTestsDone() const { return current_index_; }
        const std::vector<PerformanceResult>& getResults() const { return results_; }

    private:
        std::vector<double> rho_values_;
        std::vector<PerformanceResult> results_;
        Eigen::Matrix3d Q_nominal_ = Eigen::Matrix3d::Identity();

        int current_index_ = 0;
        double current_rho_ = 1.0;
        bool is_testing_ = false;

        // 单次测试记录
        std::vector<double> recorded_e_y_;
        std::vector<double> recorded_e_theta_;
        int64_t test_start_ns_ = 0;

        std::string formatNumber(double v, int width = 9, int prec = 4) const;
        std::string drawBar(double val, double max_val, int bar_width = 30) const;
    };

} // namespace lqr_controller

#endif // PERFORMANCE_ANALYZER_HPP