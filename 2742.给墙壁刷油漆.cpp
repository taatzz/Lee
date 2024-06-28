/*
 * @lc app=leetcode.cn id=2742 lang=cpp
 *
 * [2742] 给墙壁刷油漆
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> memo(n, vector<int>(n * 2 + 1, -1)); // -1 表示没有计算过
        auto dfs = [&](auto&& dfs, int i, int j) -> int {
            if (j > i) { // 剩余的墙都可以免费刷
                return 0;
            }
            if (i < 0) { // 上面 if 不成立，意味着 j < 0，不符合题目要求
                return INT_MAX / 2; // 防止加法溢出
            }
            // 注意 res 是引用
            int& res = memo[i][j + n]; // 加上偏移量 n，防止出现负数
            if (res != -1) { // 之前计算过
                return res;
            }
            return res = min(dfs(dfs, i - 1, j + time[i]) + cost[i], dfs(dfs, i - 1, j - 1));
        };
        return dfs(dfs, n - 1, 0);
    }
};
// @lc code=end

