/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start
class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int n = num;

        while(n)
        {
            int tmp = num % 10;
            if(num % tmp == 0)
                res ++;
            n /= 10;
        }

        return res;
    }
};
// @lc code=end

