/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0x3f3f3f3f));
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                else
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
        }

        //vector<int> dp(n + 1, 0x3f3f3f3f);

        // dp[0] = triangle[0][0];

        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = i; j >= 0; j--)
        //     {
        //         if(j)
        //             dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
        //         else
        //             dp[j] = dp[j] + triangle[i][j];
        //     }
        // }

        int res = 0x3f3f3f3f;

        for(int i = 0; i < n; i++)
        {
            res = min(res, dp[n - 1][i]);
        }

        return res;
    }
};
// @lc code=end

