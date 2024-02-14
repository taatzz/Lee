/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 20;
    long long f_mx[N][N], f_mn[N][N];

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mod = 1e9 + 7;

        for(int i = 0; i <= m; i++) f_mx[i][0] = f_mn[i][0] = 1;
        for(int j = 0; j <= n; j++) f_mx[0][j] = f_mn[0][j] = 1;

        for(int i = 1; i <= m; i++) 
            f_mx[i][1] = f_mx[i - 1][1] * grid[i - 1][0], f_mn[i][1] = f_mn[i - 1][1] * grid[i - 1][0];
        for(int j = 1; j <= n; j++) 
            f_mx[1][j] = f_mx[1][j - 1] * grid[0][j - 1], f_mn[1][j] = f_mn[1][j - 1] * grid[0][j - 1];

        for(int i = 2; i <= m; i++)
        {
            for(int j = 2; j <= n; j++)
            {
                if(grid[i - 1][j - 1] < 0)
                {
                    f_mx[i][j] = min(f_mn[i - 1][j], f_mn[i][j - 1]) * (long long)grid[i - 1][j - 1];
                    f_mn[i][j] = max(f_mx[i - 1][j], f_mx[i][j - 1]) * (long long)grid[i - 1][j - 1];
                }
                else
                {
                    f_mx[i][j] = max(f_mx[i - 1][j], f_mx[i][j - 1]) * (long long)grid[i - 1][j - 1];
                    f_mn[i][j] = min(f_mn[i - 1][j], f_mn[i][j - 1]) * (long long)grid[i - 1][j - 1];
                }
            }
        }

        return f_mx[m][n] < 0 ? -1 : f_mx[m][n] % mod;
    }
};
// @lc code=end

