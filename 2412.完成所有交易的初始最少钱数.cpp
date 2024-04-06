/*
 * @lc app=leetcode.cn id=2412 lang=cpp
 *
 * [2412] 完成所有交易的初始最少钱数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& nums) {
        long long res = 0, mx = 0;

        for(auto& e : nums)
        {
            long long a = e[0], b = e[1];
            res += max(a - b, (long long)0);
            mx = max(mx, min(a, b));
        }

        return res + mx;
    }
};
// @lc code=end

