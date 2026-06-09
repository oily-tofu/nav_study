#include "lqr_nav/performance_analyzer.hpp"

namespace lqr_controller
{

    double PerformanceAnalyzer::getNextRho() const
    {
        if (current_index_ < static_cast<int>(rho_values_.size())) {
            return rho_values_[current_index_];
        }
        return rho_values_.back();
    }

    void PerformanceAnalyzer::beginTest(double rho)
    {
        current_rho_ = rho;
        is_testing_ = true;
        recorded_e_y_.clear();
        recorded_e_theta_.clear();
        test_start_ns_ = 0; // 由调用者在第一帧设置
    }

    void PerformanceAnalyzer::record(double e_y, double e_theta)
    {
        if (!is_testing_) return;
        recorded_e_y_.push_back(e_y);
        recorded_e_theta_.push_back(e_theta);
        if (test_start_ns_ == 0) {
            // 用当前时间替代（first record time）
            // 实际时间由外部控制回调记录
        }
    }

    void PerformanceAnalyzer::endTest()
    {
        if (!is_testing_) return;
        is_testing_ = false;

        if (recorded_e_y_.empty()) {
            current_index_++;
            return;
        }

        PerformanceResult result;
        result.rho = current_rho_;

        // 计算 RMSE 和 最大横向误差
        double sum_sq_e_y = 0.0;
        double sum_sq_e_t = 0.0;
        double max_e_y = 0.0;

        for (size_t i = 0; i < recorded_e_y_.size(); ++i) {
            double ey = recorded_e_y_[i];
            double et = recorded_e_theta_[i];
            sum_sq_e_y += ey * ey;
            sum_sq_e_t += et * et;
            if (std::abs(ey) > max_e_y) max_e_y = std::abs(ey);
        }

        result.rmse_e_y = std::sqrt(sum_sq_e_y / recorded_e_y_.size());
        result.max_e_y = max_e_y;
        result.rmse_e_theta = std::sqrt(sum_sq_e_t / recorded_e_theta_.size());

        results_.push_back(result);
        current_index_++;
    }

    std::string PerformanceAnalyzer::formatNumber(double v, int width, int prec) const
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(prec) << std::setw(width) << v;
        return oss.str();
    }

    std::string PerformanceAnalyzer::drawBar(double val, double max_val, int bar_width) const
    {
        if (max_val <= 0.0) return std::string(bar_width, ' ');
        int filled = static_cast<int>(std::round((val / max_val) * bar_width));
        filled = std::max(0, std::min(filled, bar_width));

        std::string bar;
        bar.reserve(bar_width);
        for (int i = 0; i < bar_width; ++i) {
            bar += (i < filled) ? '#' : ' ';
        }
        return bar;
    }

    void PerformanceAnalyzer::printReport() const
    {
        if (results_.empty()) {
            std::cout << "\n========== Performance Report: No data ==========\n" << std::endl;
            return;
        }

        // 找最优
        double best_rmse = results_[0].rmse_e_y;
        double best_max = results_[0].max_e_y;
        int best_rmse_idx = 0;
        int best_max_idx = 0;

        for (size_t i = 1; i < results_.size(); ++i) {
            if (results_[i].rmse_e_y < best_rmse) { best_rmse = results_[i].rmse_e_y; best_rmse_idx = static_cast<int>(i); }
            if (results_[i].max_e_y < best_max)   { best_max = results_[i].max_e_y;   best_max_idx = static_cast<int>(i); }
        }

        // 找最大值用于画图
        double max_rmse = results_[0].rmse_e_y;
        for (const auto& r : results_) {
            if (r.rmse_e_y > max_rmse) max_rmse = r.rmse_e_y;
        }

        std::cout << "\n";
        std::cout << "========== LQR Performance Report ==========\n";

        // 表头
        std::cout << std::left << std::setw(8) << "rho"
                  << std::right
                  << std::setw(12) << "RMSE_e_y"
                  << std::setw(12) << "Max_e_y"
                  << std::setw(12) << "RMSE_e_t"
                  << std::setw(10) << "Time"
                  << "\n";
        std::cout << std::string(54, '-') << "\n";

        for (size_t i = 0; i < results_.size(); ++i) {
            const auto& r = results_[i];
            std::cout << std::left << std::setw(8) << r.rho
                      << std::right
                      << formatNumber(r.rmse_e_y, 12, 4) << "m"
                      << formatNumber(r.max_e_y, 12, 4) << "m"
                      << formatNumber(r.rmse_e_theta, 12, 4) << "rad"
                      << formatNumber(r.completion_time, 9, 2) << "s"
                      << (r.is_best_rmse ? "  ← best RMSE" : "")
                      << (r.is_best_max ? "  ← best Max" : "")
                      << "\n";
        }

        // ASCII 柱状图
        std::cout << "\n--- RMSE_e_y by rho (lower is better) ---\n";
        for (const auto& r : results_) {
            std::cout << std::left << std::setw(6) << r.rho << " "
                      << drawBar(r.rmse_e_y, max_rmse, 30) << "  "
                      << r.rmse_e_y
                      << (r.rmse_e_y == best_rmse ? "  ← min" : "")
                      << "\n";
        }

        std::cout << "\n--- Max_e_y by rho (lower is better) ---\n";
        double max_max = results_[0].max_e_y;
        for (const auto& r : results_) if (r.max_e_y > max_max) max_max = r.max_e_y;
        for (const auto& r : results_) {
            std::cout << std::left << std::setw(6) << r.rho << " "
                      << drawBar(r.max_e_y, max_max, 30) << "  "
                      << r.max_e_y
                      << (r.max_e_y == best_max ? "  ← min" : "")
                      << "\n";
        }

        const auto& best_rmse_r = results_[best_rmse_idx];
        const auto& best_max_r = results_[best_max_idx];
        std::cout << "\nRecommended ρ = " << best_rmse_r.rho
                  << " (min RMSE_e_y=" << best_rmse_r.rmse_e_y << "m)"
                  << "\n";
        if (best_rmse_idx != best_max_idx) {
            std::cout << "Best Max_e_y at ρ = " << best_max_r.rho
                      << " (Max_e_y=" << best_max_r.max_e_y << "m)"
                      << "\n";
        }
        std::cout << "==========================================\n" << std::endl;
    }

} // namespace lqr_controller