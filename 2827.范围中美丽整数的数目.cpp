/*
 * @lc app=leetcode.cn id=2827 lang=cpp
 *
 * [2827] 范围中美丽整数的数目
 */

// @lc code=start
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int mem[35][25][70];
    int _k;

    int dfs(string& s, int x, int val, int dif, bool is_limit, bool is_num)
    {
        int n = s.size();
        if(x == n)
        {
            return is_num && val == 0 && dif == n;
        }
        if(!is_limit && is_num && mem[x][val][dif] != -1) return mem[x][val][dif];

        int res = 0;
        if(!is_num) res = dfs(s, x + 1, val, dif, false, false);
        
        int hi = is_limit ? s[x] - '0' : 9;
        for(int i = 1 - is_num; i <= hi; i++)
        {
            res += dfs(s, x + 1, (val * 10 + i) % _k, dif + i % 2 * 2 - 1, is_limit && i == hi, true);
        }
        if(!is_limit && is_num) mem[x][val][dif] = res;

        return res;
    }

    int find(int x)
    {
        string s = to_string(x);
        memset(mem, -1, sizeof mem);

        return dfs(s, 0, 0, s.size(), true, false);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        _k = k;

        return find(high) - find(low - 1);
    }
};
// @lc code=end

