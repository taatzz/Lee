/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int dy[2] = { 1,-1 };
    static const int N = 210;
    int mem[N][N];

    // 记忆化搜索
    int dfs(vector<vector<int>>& g, int x, int y)
    {
        int n = g.size();
        if(x >= n) return 0;
        if(mem[x][y]) return mem[x][y];

        int res = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            if(j == y) continue;
            res = min(res, g[x][y] + dfs(g, x + 1, j));
        }
        mem[x][y] = res;

        return res;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];

        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int t = dfs(grid, 0, i);
            res = min(res, t);;
        }

        // 1:1翻译成递推
        // vector<vector<int>> f(n, vector<int> (n, 1e9));
        // for(int i = 0; i < n; i++) f[n - 1][i] = grid[n - 1][i];
        // int res = INT_MAX;

        // for(int i = n - 2; i >= 0; i--)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         for(int k = 0; k < n; k ++)
        //         {
        //             if(k == j) continue;
        //             f[i][j] = min(f[i][j], f[i + 1][k] + grid[i][j]);
        //         }
        //         if(i == 0) res = min(res, f[i][j]);
        //     }
        // }

        return res;
    }
};
// @lc code=end

