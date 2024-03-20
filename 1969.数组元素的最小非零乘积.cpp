/*
 * @lc app=leetcode.cn id=1969 lang=cpp
 *
 * [1969] 数组元素的最小非零乘积
 */

// @lc code=start
class Solution {
public:
    static const int mod = 1e9 + 7;

    long long qmi(long long a, long long b)
    {
        long long res = 1 % mod;
        a %= mod;
        while(b)
        {
            res = res * a % mod;
            a = (long long) a * a % mod;
            b--;
        }

        return res;
    }

    int minNonZeroProduct(int p) {
        long long k = (1LL << p) - 1;
        return k % mod * qmi(k - 1, p - 1) % mod;
    }
};
// @lc code=end

