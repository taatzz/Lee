/*
 * @lc app=leetcode.cn id=2571 lang=cpp
 *
 * [2571] 将整数减少到零需要的最少操作数
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    static const int N = 200010;
    int mem[N];

    int lowbit(int x)
    {
        return x & -x;
    }

    int dfs(int x)
    {
        int t = lowbit(x);
        if(x - t == 0) return 1;

        int& res = mem[x];
        if(res) return res;
        res = std::min(dfs(x + t) + 1, dfs(x - t) + 1);
        return res;
    }

    int minOperations(int n) {
        
        return dfs(n);
    }
};
// @lc code=end

