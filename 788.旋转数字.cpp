/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    string path;
    int mem[25][2];
    unordered_map<char, int> h;

    int dfs(string s, int x, bool is_limit, bool has_dif)
    {
        int n = s.size();
        if(x == n)
        {
            // 翻转之后是否不同。
            return has_dif;
        }
        if(!is_limit && mem[x][has_dif] != -1) return mem[x][has_dif]; 

        int hi = is_limit ? s[x] - '0' : 9;

        int res = 0;
        for(int i = 0; i <= hi; i++)
        {
            char c = i + '0';
            if(h.find(c) == h.end()) continue;
            res += dfs(s, x + 1, is_limit && i == hi, has_dif || h[c]);
        }
        if(!is_limit) mem[x][has_dif] = res;

        return res;
    }

    int rotatedDigits(int n) {
        memset(mem, -1, sizeof mem);
        string s = to_string(n);
        h['0'] = 0;
        h['1'] = 0;
        h['2'] = 1;
        h['5'] = 1;
        h['6'] = 1;
        h['9'] = 1;
        h['8'] = 0;

        return dfs(s, 0, true, false);
    }
};
// @lc code=end

