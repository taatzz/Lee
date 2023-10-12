/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;    

class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int res = INT_MIN;
    //     int cnt = 0;
    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         cnt += nums[i];
    //         if(cnt > res)
    //             res = cnt;
    //         if(cnt <=0)
    //             cnt = 0;
    //     }
    //     return res;
    // }

    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();

        // dp[i] 表示包含下标为i的连续子序列的和为dp[i]
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        // 无后效性
        // dp[i] = max(dp[i-1] + nums[i], nums[i])
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if(dp[i] > res)
                res = dp[i];
        }

        return res;
    }
};
// @lc code=end

