/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> f(high + 1);

        int res = 0, mod = 1e9 + 7;
        f[0] = 1;
        for(int i = 1; i <= high; i++)
        {
            if(i >= zero) f[i] = (f[i] + f[i - zero]) % mod;
            if(i >= one) f[i] = (f[i] + f[i - one]) % mod;
            if(i >= low) res = (res + f[i]) % mod;
        } 

        return res;
    }
};
// @lc code=end

