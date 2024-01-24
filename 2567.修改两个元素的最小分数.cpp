/*
 * @lc app=leetcode.cn id=2567 lang=cpp
 *
 * [2567] 修改两个元素的最小分数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // 将两个小值变大 nums[n - 1] - nums[2]
        // 将两个大值变小 nums[n - 3] - nums[0]
        // 将最小值变大和最大值变小 nums[n - 2] - nums[1]
        return min(nums[n - 2] - nums[1], min(nums[n - 1] - nums[2], nums[n - 3] - nums[0]));
    }
};
// @lc code=end

