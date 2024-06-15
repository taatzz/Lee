/*
 * @lc app=leetcode.cn id=2779 lang=cpp
 *
 * [2779] 数组的最大美丽值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++)
        {
            int idx = upper_bound(nums.begin() + i, nums.end(), nums[i] + 2 * k) - nums.begin();
            res = max(res, idx - i);
        }

        return res;
    }
};
// @lc code=end

