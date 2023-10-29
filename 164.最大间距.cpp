/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        sort(nums.begin(), nums.end());

        int res = 0;
        for(int i = 1; i < n; i++)
        {
            res = max(res, nums[i] - nums[i - 1]);
        }

        return res;
    }
};
// @lc code=end

