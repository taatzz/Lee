/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0; // 滑动窗口左端和右端
        int res = 1e9, sum = 0;

        // 当前滑动窗口总和小于目标值继续扩展窗口右端，窗口总和大于目标值，缩小左端
        while(right < n)
        {
            if(sum + nums[right] < target)
            {
                sum += nums[right];
                right++;
            }
            else
            {
                res = min(res, right - left + 1);
                sum -= nums[left++];
            }
        }

        return res == 1e9 ? 0 : res;
    }
};
// @lc code=end

