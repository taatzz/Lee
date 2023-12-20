/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

class Solution {
public:
    bool check(long long mid, int n, int a, int b)
    {
        int sum_a = mid / a;
        int sum_b = mid / b;
        int sum = mid / lcm(a, b);

        return sum_a + sum_b - sum >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7;
        long long l = 0, r = min(a, b) * (long long)n;

        while(l < r)
        {
            long long mid = (long long)(l + r) >> 1;
            if(check(mid, n, a, b)) r = mid;
            else l = mid + 1;
        }

        return l % mod;
    }
};
// @lc code=end

