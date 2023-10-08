/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, 0);

        dp[0] = 1;
        for(int i = 0; i <= target; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(i - nums[j] > 0 && dp[i] < INT_MAX - dp[i-nums[j]])
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};
// @lc code=end

