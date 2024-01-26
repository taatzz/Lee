/*
 * @lc app=leetcode.cn id=1922 lang=cpp
 *
 * [1922] 统计好数字的数目
 */

// @lc code=start
class Solution {
public:
    int mod = 1e9 + 7;

    int qmi(int a, long long b)
    {
        long long res = 1;
        while(b)
        {
            if(b & 1) res = res * a % mod;
            a = (long long)a * a % mod;
            b >>= 1;
        }

        return res;
    }

    int countGoodNumbers(long long n) {
        if(n % 2 == 1)
        {
            long long odd = n / 2 + 1;
            long long even = n - odd;
            return even == 0 ? qmi(5, odd) : (long long)qmi(5, odd) * qmi(4, even) % mod;
        }
        else
        {
            long long odd = n / 2;
            return (long long)qmi(5, odd) * qmi(4, odd) % mod;
        }
    }
};
// @lc code=end

