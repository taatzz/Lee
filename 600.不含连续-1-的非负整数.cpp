/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
#include <functional>
#include <cstring>

using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        int m = 0, st = 0;
        for(int i = 31; i >= 0; i--)
        {
            if((n >> i & 1) == 1)
            {
                st = 1;
            }
            if(st) m++;
        }

        int mem[35][2];
        memset(mem, -1, sizeof mem);
        function<int(int, int, int, bool)> dfs = [&](int n, int x, int pre, bool is_limit)
        {
            if(x < 0) return 1;

            int hi = is_limit ? (n >> x & 1) : 1;
            if(!is_limit && mem[x][pre] != -1) return mem[x][pre];

            int res = 0;
            for(int i = 0; i <= hi; i++)
            {
                if(pre & i == 1) continue;
                res += dfs(n, x - 1, i, is_limit && i == hi);
            }

            if(!is_limit) mem[x][pre] = res;
            return res;
        };

        return dfs(n, m, 0, true);
    }
};
// @lc code=end

