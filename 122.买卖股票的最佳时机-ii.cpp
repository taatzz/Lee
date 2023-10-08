/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][j] 表示当前手上的现金
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        // 0：表示不持有股票dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        // 1：表示持有股票  dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }

};
// @lc code=end

