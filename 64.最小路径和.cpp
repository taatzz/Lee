/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        // dp[i][j] 表示当前终点的最小路径和
        vector<vector<int> > dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        // 第一列只能由上面的元素推导
        for(int i = 1; i < m; i++)
        {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        // 第一行只能由左面的元素推导
        for(int j = 1; j < n; j++)
        {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        /*  i > 0 j > 0
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
        */
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

