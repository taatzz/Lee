/*
 * @lc app=leetcode.cn id=2684 lang=cpp
 *
 * [2684] 矩阵中移动的最大次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int mem[N][N];

    int dfs(vector<vector<int>>& g, int x, int y)
    {
        int& res = mem[x][y];
        int m = g.size(), n = g[0].size();

        if(res) return res;

        int cnt = 0;
        for(int i = -1; i <= 1; i++)
        {
            if(x + i >= 0 && x + i < m && y + 1 < n && g[x][y] < g[x + i][y + 1])
                cnt = max(cnt, dfs(g, x + i, y + 1) + 1);
        }

        return res = cnt;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(mem, 0, sizeof mem);

        int res = 0;
        for(int i = 0; i < m; i++)
        {
            res = max(res, dfs(grid, i, 0));
        }

        return res;
    }
};
// @lc code=end

