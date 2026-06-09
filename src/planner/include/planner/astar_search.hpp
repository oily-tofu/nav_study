#ifndef ASTAR_SEARCH_HPP
#define ASTAR_SEARCH_HPP

#include <vector>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <cstdint>

namespace planner
{

/**
 * @brief A* 节点结构体
 */
struct Node {
    int x, y;       // 栅格坐标
    double g, h, f; // g: 实际代价, h: 启发式代价, f = g + h
    int parent_idx; // 父节点索引（在节点数组中的索引）

    Node() : x(0), y(0), g(0), h(0), f(0), parent_idx(-1) {}
    Node(int _x, int _y) : x(_x), y(_y), g(0), h(0), f(0), parent_idx(-1) {}
};

/**
 * @brief 优先队列中使用的包装节点（用于按 f 值排序）
 */
struct NodeOpen {
    int idx;    // 在节点数组中的索引
    double f;   // f 值

    bool operator>(const NodeOpen& other) const {
        return f > other.f;
    }
};

/**
 * @brief A* 配置参数
 */
struct AStarConfig {
    double heuristic_weight = 1.0;  // 启发式权重（>1.0 为加权 A*）
    bool use_8_connectivity = true; // 是否使用 8 连通
    double resolution = 0.05;       // 地图分辨率（m/像素）
    double origin_x = 0.0;          // 地图原点 x（世界坐标）
    double origin_y = 0.0;          // 地图原点 y（世界坐标）
    int map_width = 0;              // 地图宽度（像素）
    int map_height = 0;             // 地图高度（像素）
};

/**
 * @brief A* 搜索算法核心类
 */
class AStarSearch
{
public:
    AStarSearch();
    ~AStarSearch() = default;

    /**
     * @brief 设置占用栅格地图
     * @param costmap 占用栅格数据（-1=未知, 0=自由, 100=障碍物）
     * @param width   地图宽度（像素）
     * @param height  地图高度（像素）
     * @return 是否成功
     */
    bool setMap(const std::vector<int8_t>& costmap, int width, int height);

    /**
     * @brief 设置 A* 配置
     */
    void setConfig(const AStarConfig& config);

    /**
     * @brief 获取当前配置
     */
    const AStarConfig& getConfig() const { return config_; }

    /**
     * @brief 世界坐标转栅格坐标
     * @param wx  世界坐标 x
     * @param wy  世界坐标 y
     * @param gx  输出：栅格坐标 x
     * @param gy  输出：栅格坐标 y
     * @return 是否在地图范围内
     */
    bool worldToGrid(double wx, double wy, int& gx, int& gy) const;

    /**
     * @brief 栅格坐标转世界坐标（栅格中心点）
     */
    void gridToWorld(int gx, int gy, double& wx, double& wy) const;

    /**
     * @brief 检查栅格是否可通行
     */
    bool isTraversable(int gx, int gy) const;

    /**
     * @brief 执行 A* 路径搜索
     * @param start_x  起点世界坐标 x
     * @param start_y  起点世界坐标 y
     * @param goal_x   终点世界坐标 x
     * @param goal_y   终点世界坐标 y
     * @param path     输出：路径点列表（世界坐标，pair<x, y>）
     * @return 是否找到路径
     */
    bool plan(double start_x, double start_y,
              double goal_x, double goal_y,
              std::vector<std::pair<double, double>>& path);

    /**
     * @brief 清除路径缓存
     */
    void clearPath();

private:
    /**
     * @brief 计算两点间的欧氏距离（启发式函数）
     */
    double heuristic(int x1, int y1, int x2, int y2) const;

    /**
     * @brief 获取从 start 到 neighbor 的移动代价
     */
    double movementCost(int dx, int dy) const;

    /**
     * @brief 检查栅格是否在地图范围内
     */
    bool isValid(int x, int y) const;

    /**
     * @brief 检查是否有障碍物阻挡走对角线（防止穿墙）
     */
    bool hasObstacleBetween(int x1, int y1, int x2, int y2) const;

    // 地图数据
    std::vector<int8_t> costmap_;
    int map_width_;
    int map_height_;

    // 配置
    AStarConfig config_;

    // 路径结果（栅格坐标）
    std::vector<std::pair<int, int>> grid_path_;

    // 8 连通方向
    static const int dx_[8];
    static const int dy_[8];
};

} // namespace planner

#endif // ASTAR_SEARCH_HPP