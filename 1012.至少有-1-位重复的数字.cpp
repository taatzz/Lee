/*
 * @lc app=leetcode.cn id=1012 lang=cpp
 *
 * [1012] 至少有 1 位重复的数字
 */

// @lc code=start
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int mem[35][1050];

    int dfs(string s, int x, int mask, bool is_limit, bool is_num)
    {
        int n = s.size();
        if(x == n)
        {
            return is_num;
        }
        if(!is_limit && is_num && mem[x][mask] != -1) return mem[x][mask];
        int res = 0;

        if(!is_num) res += dfs(s, x + 1, mask, false, false);

        int hi = is_limit ? s[x] - '0' : 9;
        for(int i = 1 - is_num; i <= hi; i++)
        {
            if((mask >> i & 1) == 1) continue;
            res += dfs(s, x + 1, (mask | (1 << i)), is_limit && i == hi, true);
        }
        if(!is_limit && is_num) mem[x][mask] = res;

        return res;
    }

    // 正难则反，求出无重复的数字答案就是 n - res
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(mem, -1, sizeof mem);

        int res = dfs(s, 0, 0, true, false);

        return n - res;
    }
};
// @lc code=end

