/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 1)
            return nums.size();
        int n = nums.size();
        vector<int> dp(n, 1);

        int res = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] < nums[i])
                dp[i] = dp[i-1] + 1;

            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

