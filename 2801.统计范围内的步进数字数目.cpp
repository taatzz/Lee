/*
 * @lc app=leetcode.cn id=2801 lang=cpp
 *
 * [2801] 统计范围内的步进数字数目
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int mem[110][10];
    
    int dfs(string& s, int x, int pre, bool is_limit, bool is_num)
    {
        int n = s.size();
        if(x == n)
        {
            return is_num;
        }
        if(!is_limit && is_num && mem[x][pre] != -1) return mem[x][pre];
        int res = 0;

        if(!is_num) res = dfs(s, x + 1, pre, 0, 0);

        int hi = is_limit ? s[x] - '0' : 9;
        for(int i = 1 - is_num; i <= hi; i++)
        {
            if(!is_num || abs(i - pre) == 1)
            {
                res = (res + dfs(s, x + 1, i, is_limit && i == hi, true)) % mod;
            }
        }
        if(!is_limit && is_num) mem[x][pre] = res;

        return res;
    }

    int countSteppingNumbers(string low, string high) {
        bool flag = true;
        for(int i = 1; i < low.size(); i++)
        {
            if(abs((int)low[i] - (int)low[i - 1]) != 1)
            {
                flag = false;
                break;
            }
        }
        memset(mem, -1, sizeof mem);
        long long r = dfs(high, 0, 0, true, false);
        memset(mem, -1, sizeof mem);
        long long l = dfs(low, 0, 0, 1, 0);

        return (r - l + flag + mod) % mod;
    }
};
// @lc code=end

