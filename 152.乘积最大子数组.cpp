/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f_max(n, INT_MIN);
        vector<int> f_min(n, INT_MAX);
        f_max[0] = nums[0], f_min[0] = nums[0];

        for(int i = 1; i < n; i++)
        {
            f_max[i] = max(f_max[i - 1] * nums[i], max(nums[i], f_min[i - 1] * nums[i]));
            f_min[i] = min(f_min[i - 1] * nums[i], min(nums[i], f_max[i - 1] * nums[i]));
        }


        return *max_element(f_max.begin(), f_max.end());
    }
};
// @lc code=end

