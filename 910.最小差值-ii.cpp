/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int res = nums[n - 1] - nums[0]; 
        for(int i = 1; i < n; i++)
        {
            int lo = min(nums[0] + k, nums[i] - k);
            int hi = max(nums[i - 1] + k, nums[n - 1] - k);
            res = min(res, hi - lo);
        }

        return res;
    }
};
// @lc code=end

