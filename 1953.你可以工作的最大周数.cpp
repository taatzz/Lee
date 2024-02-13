/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 *
 * [1953] 你可以工作的最大周数
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        if(sum < nums[nums.size() - 1] * 2) return (long long)(sum - nums[nums.size() - 1]) * 2 + 1;

        return sum;
    }
};
// @lc code=end

