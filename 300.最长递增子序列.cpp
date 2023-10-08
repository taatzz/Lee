/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int n = nums.size();
        vector<int> dp(n, 1);

        int res = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

