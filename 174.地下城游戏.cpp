/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 210;
    int mem[N][N];

    int dfs(vector<vector<int>>& g, int x, int y)
    {
        int n = g.size(), m = g[0].size();

        if(x < 0 || x >= n || y < 0 || y >= m)
            return INT_MAX;

        if(x == n - 1 && y == m - 1)
        {
            return g[x][y] >= 0 ? 1 : -g[x][y] + 1;
        }

        int& res = mem[x][y];
        if(res) return res;

        int a = dfs(g, x + 1, y);
        int b = dfs(g, x, y + 1);

        int t = min(a, b) - g[x][y];
        return res = t <= 0 ? 1 : t;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return dfs(dungeon, 0, 0);
    }
};
// @lc code=end

