/*
 * @lc app=leetcode.cn id=1509 lang=cpp
 *
 * [1509] 三次操作后最大值与最小值的最小差
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n <= 4) return 0;
        else
        {
            int res = INT_MAX;
            res = min(res, abs(nums[n - 4] - nums[0]));
            res = min(res, abs(nums[n - 3] - nums[1]));
            res = min(res, abs(nums[n - 2] - nums[2]));
            res = min(res, abs(nums[n - 1] - nums[3]));

            return res;
        }
    }
};
// @lc code=end

