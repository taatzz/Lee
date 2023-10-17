/*
 * @lc app=leetcode.cn id=2652 lang=cpp
 *
 * [2652] 倍数求和
 */

// @lc code=start
class Solution {
public:
    int sumOfMultiples(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!(i % 3) || !(i % 5) || !(i % 7))
                res += i;
        }

        return res;
    }
};
// @lc code=end

