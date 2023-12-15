/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    typedef long long LL;
    double qmi(double a, LL b)
    {
        double res = 1.0;
        while(b > 0)
        {
            if(b % 2 == 1) res = res * a;
            b >>= 1;
            a *= a;
        }        
        return res;
    }
    double myPow(double x, int n) {
        LL N = n;
        // 指数为负数时，返回1/qmi
        return N >= 0 ? qmi(x, N) : 1.0 / qmi(x, -N);
    }
};
// @lc code=end

