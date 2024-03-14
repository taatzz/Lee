/*
 * @lc app=leetcode.cn id=2789 lang=cpp
 *
 * [2789] 合并后数组中的最大元素
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long res = nums[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            res = nums[i] <= res ? res + nums[i] : nums[i];
        }

        return res;
    }
};
// @lc code=end

