/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 正序DP：dp[i] 表示当前以第i个问题结尾的最高分数，当前第i个问题如果不回答就有dp[i]=dp[i-1]
    // 如果回答则是上一个问题的冷冻期结束，所以我们需要遍历[1,i) 的所有问题
    // 但是如果这样的话时间复杂度就是O(n^2)是一定会超时的
    // 对于当前问题我们如果解决就只能解决冷冻期之后的题目，所以我们考虑从后向前遍历
    // dp[i]表示当前第i个题目以及之后所有题目的最高分
    // 不解决当前问题 dp[i] = dp[i + 1];
    // 解决当前问题 dp[i] = max(dp[i], w + dp[i + j]);
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();

        vector<int> dp(n + 1);
        
        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = dp[i - 1];
            int j = min(n, i + q[i][1]);
            dp[i] = max(dp[i], dp[j] + q[i][0]);
        }

        return dp[0];
    }
};
// @lc code=end

