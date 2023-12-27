/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = INT_MAX;
        for(int i = k - 1; i < n; i++)
        {
            int j = i - k + 1;
            res = min(res, nums[i] - nums[j]);
        }

        return res;
    }
};
// @lc code=end

