/*
 * @lc app=leetcode.cn id=2110 lang=cpp
 *
 * [2110] 股票平滑下跌阶段的数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        // dp[i]: 表示当前以i为结尾的平稳下滑的天数
        // dp[i] = 1 || dp[i] = dp[i - 1] + 1;
        // 所有数的和即为答案
        vector<int> dp(n);

        dp[0] = 1;
        long long res = 1;
        for(int i = 1; i < n; i++)
        {
            if(prices[i - 1] - prices[i] == 1) 
                dp[i] = dp[i - 1] + 1;
            else dp[i] = 1;
            res += dp[i];
        }

        return res;
    }
};
// @lc code=end

