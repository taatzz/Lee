/*
 * @lc app=leetcode.cn id=2457 lang=cpp
 *
 * [2457] 美丽整数的最小增量
 */

// @lc code=start
class Solution {
public:
    long long cnt(long long x)
    {
        int res = 0;
        while(x)
        {
            res += x % 10;
            x /= 10;
        }

        return res;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        if(cnt(n) <= cnt(target)) return 0; 

        long long x = n;
        long long i = 10;
        while(cnt(x) > target)
        {
            x = x / i;
            x ++;
            x *= i;
            i *= 10;
        }  

        return x - n;
    }
};
// @lc code=end

