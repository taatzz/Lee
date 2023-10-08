/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        vector<vector<int> > dp(n, vector<int>(sum / 2, 0));
        for(int j = nums[0]; j <= sum / 2; j++)
            dp[0][j] = nums[0];

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum / 2; j++)
            {
                if(j < nums[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - nums[i]] + nums[i]);
            }
        }

        return dp[n-1][sum / 2] == sum / 2;
    }
};
// @lc code=end

