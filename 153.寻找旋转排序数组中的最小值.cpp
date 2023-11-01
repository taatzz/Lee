/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(nums[0] <= nums[mid]) l = mid;
            else r = mid - 1;
        }

        return r + 1 < n ? nums[r + 1] : nums[0];
    }
};
// @lc code=end

