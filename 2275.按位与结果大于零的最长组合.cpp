/*
 * @lc app=leetcode.cn id=2275 lang=cpp
 *
 * [2275] 按位与结果大于零的最长组合
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for(int i = 0; i < 26; i++)
        {
            int t = 0;
            for(auto e : nums)
            {
                if((e & (1 << i)) == (1 << i)) t++;
            }
            res = max(res, t);
        }

        return res;
    }
};
// @lc code=end

