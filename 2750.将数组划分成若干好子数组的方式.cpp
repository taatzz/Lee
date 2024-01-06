/*
 * @lc app=leetcode.cn id=2750 lang=cpp
 *
 * [2750] 将数组划分成若干好子数组的方式
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        int res = 1, mod = 1e9 + 7;

        int pre = -1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) continue;
            if(pre >= 0) res = (long long)res * (i - pre) % mod;
            pre = i;
        }

        return pre < 0 ? 0 : res;
    }
};
// @lc code=end

