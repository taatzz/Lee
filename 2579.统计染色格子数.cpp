/*
 * @lc app=leetcode.cn id=2579 lang=cpp
 *
 * [2579] 统计染色格子数
 */

// @lc code=start
class Solution {
public:
    long long f[100010];
    long long coloredCells(long long n) {
        f[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + (2 * (i - 1)) * 2;
        }

        return f[n];
    }
};
// @lc code=end

