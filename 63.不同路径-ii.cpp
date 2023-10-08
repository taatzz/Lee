/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i ++)
        {
            if(obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
        }
        for(int j = 0; j < n; j++)
        {
            if(obstacleGrid[0][j] != 1)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }
        dp[0][0] = 0;

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = 0;
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

