/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int low = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int upper = nums.end() - upper_bound(nums.begin(), nums.end(), 0);

        return max(low, upper);
    }
};
// @lc code=end

