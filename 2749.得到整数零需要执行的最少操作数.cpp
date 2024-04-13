/*
 * @lc app=leetcode.cn id=2749 lang=cpp
 *
 * [2749] 得到整数零需要执行的最少操作数
 */

// @lc code=start

class Solution {
public:

    int makeTheIntegerZero(int num1, int num2) {

        for(long long k = 1; k <= num1 - num2 * k; k++)
        {
            if(k >= __builtin_popcountll(num1 - num2 * k)) return k;
        }

        return -1;
    }
};
// @lc code=end

