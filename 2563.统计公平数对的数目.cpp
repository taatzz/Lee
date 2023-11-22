/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 *
 * [2563] 统计公平数对的数目
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            auto r = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            auto l = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);

            res += r - l;
        }

        return res;
    }
};
// @lc code=end

