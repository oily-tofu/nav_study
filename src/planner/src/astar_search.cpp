#include "planner/astar_search.hpp"
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace planner
{

// 8 连通方向（包括对角线）
const int AStarSearch::dx_[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int AStarSearch::dy_[8] = {0, 1, 1, 1, 0, -1, -1, -1};

AStarSearch::AStarSearch()
    : map_width_(0)
    , map_height_(0)
{
}

bool AStarSearch::setMap(const std::vector<int8_t>& costmap, int width, int height)
{
    if (width <= 0 || height <= 0) {
        return false;
    }
    if (static_cast<int>(costmap.size()) != width * height) {
        return false;
    }

    costmap_ = costmap;
    map_width_ = width;
    map_height_ = height;
    config_.map_width = width;
    config_.map_height = height;

    return true;
}

void AStarSearch::setConfig(const AStarConfig& config)
{
    config_ = config;
    config_.map_width = map_width_;
    config_.map_height = map_height_;
}

bool AStarSearch::worldToGrid(double wx, double wy, int& gx, int& gy) const
{
    gx = static_cast<int>(std::floor((wx - config_.origin_x) / config_.resolution));
    gy = static_cast<int>(std::floor((wy - config_.origin_y) / config_.resolution));
    return isValid(gx, gy);
}

void AStarSearch::gridToWorld(int gx, int gy, double& wx, double& wy) const
{
    wx = config_.origin_x + (gx + 0.5) * config_.resolution;
    wy = config_.origin_y + (gy + 0.5) * config_.resolution;
}

bool AStarSearch::isValid(int x, int y) const
{
    return x >= 0 && x < map_width_ && y >= 0 && y < map_height_;
}

bool AStarSearch::isTraversable(int gx, int gy) const
{
    if (!isValid(gx, gy)) {
        return false;
    }
    int idx = gy * map_width_ + gx;
    // 障碍物（occupied_thresh > 0.65, 即 > 65）或未知（-1）不可通行
    return costmap_[idx] >= 0 && costmap_[idx] < 65;
}

double AStarSearch::heuristic(int x1, int y1, int x2, int y2) const
{
    if (config_.use_8_connectivity) {
        // 对角线距离（允许 8 方向移动时的最优启发式）
        double dx = std::abs(x1 - x2);
        double dy = std::abs(y1 - y2);
        return std::max(dx, dy);
    } else {
        // 曼哈顿距离
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    }
}

double AStarSearch::movementCost(int dx, int dy) const
{
    if (dx == 0 || dy == 0) {
        return 1.0;  // 4 连通移动代价
    } else {
        return std::sqrt(2.0);  // 对角线移动代价
    }
}

bool AStarSearch::hasObstacleBetween(int x1, int y1, int x2, int y2) const
{
    // 对角线移动时，检查两个相邻的 4 连通栅格是否有障碍物
    // 例如向右上移动时，检查 (x1+1, y1) 和 (x1, y1+1)
    if (x1 != x2 && y1 != y2) {
        if (!isTraversable(x1, y2) || !isTraversable(x2, y1)) {
            return true;
        }
    }
    return false;
}

bool AStarSearch::plan(double start_x, double start_y,
                        double goal_x, double goal_y,
                        std::vector<std::pair<double, double>>& path)
{
    // 清空之前的路径
    clearPath();
    path.clear();

    // 转换起止点到栅格坐标
    int start_gx, start_gy, goal_gx, goal_gy;
    if (!worldToGrid(start_x, start_y, start_gx, start_gy)) {
        return false;
    }
    if (!worldToGrid(goal_x, goal_y, goal_gx, goal_gy)) {
        return false;
    }

    // 检查起止点是否可通行
    if (!isTraversable(start_gx, start_gy) || !isTraversable(goal_gx, goal_gy)) {
        return false;
    }

    // 如果起点和终点是同一个栅格，直接返回
    if (start_gx == goal_gx && start_gy == goal_gy) {
        double wx, wy;
        gridToWorld(start_gx, start_gy, wx, wy);
        path.emplace_back(wx, wy);
        grid_path_.emplace_back(start_gx, start_gy);
        return true;
    }

    // A* 搜索
    // 使用一维数组存储节点
    int total_cells = map_width_ * map_height_;
    std::vector<Node> nodes(total_cells);
    std::vector<bool> closed(total_cells, false);

    // 优先队列（最小堆）
    std::priority_queue<NodeOpen, std::vector<NodeOpen>, std::greater<NodeOpen>> open_set;

    // 初始化起点
    int start_idx = start_gy * map_width_ + start_gx;
    nodes[start_idx].x = start_gx;
    nodes[start_idx].y = start_gy;
    nodes[start_idx].g = 0.0;
    nodes[start_idx].h = heuristic(start_gx, start_gy, goal_gx, goal_gy);
    nodes[start_idx].f = nodes[start_idx].g + config_.heuristic_weight * nodes[start_idx].h;
    nodes[start_idx].parent_idx = -1;

    open_set.push({start_idx, nodes[start_idx].f});

    // 搜索主循环
    int goal_idx = goal_gy * map_width_ + goal_gx;
    bool found = false;
    int max_iterations = total_cells * 2;
    int iteration = 0;

    while (!open_set.empty() && iteration < max_iterations) {
        // 取出 f 值最小的节点
        NodeOpen current = open_set.top();
        open_set.pop();

        // 跳过已关闭的节点（延迟删除）
        if (closed[current.idx]) {
            continue;
        }

        // 标记为已关闭
        closed[current.idx] = true;
        iteration++;

        // 到达目标
        if (current.idx == goal_idx) {
            found = true;
            break;
        }

        // 获取当前节点坐标
        int cx = nodes[current.idx].x;
        int cy = nodes[current.idx].y;

        // 扩展邻居
        int num_directions = config_.use_8_connectivity ? 8 : 4;
        for (int dir = 0; dir < num_directions; ++dir) {
            int nx = cx + dx_[dir];
            int ny = cy + dy_[dir];

            // 检查是否在地图范围内
            if (!isValid(nx, ny)) {
                continue;
            }

            // 检查是否可通行
            if (!isTraversable(nx, ny)) {
                continue;
            }

            // 对角线时检查是否有障碍物阻挡
            if (dx_[dir] != 0 && dy_[dir] != 0) {
                if (hasObstacleBetween(cx, cy, nx, ny)) {
                    continue;
                }
            }

            int nidx = ny * map_width_ + nx;

            // 已关闭则跳过
            if (closed[nidx]) {
                continue;
            }

            // 计算移动代价
            double move_cost = movementCost(dx_[dir], dy_[dir]);
            double tentative_g = nodes[current.idx].g + move_cost;

            // 如果该节点尚未被访问过，或找到了更优的路径
            if (nodes[nidx].parent_idx == -1 || tentative_g < nodes[nidx].g) {
                nodes[nidx].x = nx;
                nodes[nidx].y = ny;
                nodes[nidx].g = tentative_g;
                nodes[nidx].h = heuristic(nx, ny, goal_gx, goal_gy);
                nodes[nidx].f = nodes[nidx].g + config_.heuristic_weight * nodes[nidx].h;
                nodes[nidx].parent_idx = current.idx;

                open_set.push({nidx, nodes[nidx].f});
            }
        }
    }

    if (!found) {
        return false;
    }

    // 回溯路径
    std::vector<std::pair<int, int>> raw_path;
    int cur_idx = goal_idx;
    while (cur_idx != -1) {
        int gx = nodes[cur_idx].x;
        int gy = nodes[cur_idx].y;
        raw_path.emplace_back(gx, gy);
        cur_idx = nodes[cur_idx].parent_idx;
    }
    std::reverse(raw_path.begin(), raw_path.end());

    // 保存栅格路径
    grid_path_ = raw_path;

    // 转换为世界坐标
    for (const auto& gp : raw_path) {
        double wx, wy;
        gridToWorld(gp.first, gp.second, wx, wy);
        path.emplace_back(wx, wy);
    }

    return true;
}

void AStarSearch::clearPath()
{
    grid_path_.clear();
}

} // namespace planner