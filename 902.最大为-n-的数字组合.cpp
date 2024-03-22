/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

class Solution {
public:
    unordered_set<string> h;
    int mem[35];

    int dfs(vector<string>& word, string s, int x, bool is_limit, bool is_num)
    {
        int n = s.size();
        if(x == n)  
        {
            return is_num;
        }
        if(!is_limit && is_num && mem[x] != -1) return mem[x];

        int res = 0;
        // 前面的都没有选，则当前位置可以不选
        if(!is_num) res = dfs(word, s, x + 1, false, false);

        char hi = is_limit? s[x] : '9';
        for(auto& d : word)
        {
            if(d[0] > hi) break;
            res += dfs(word, s, x + 1, is_limit && d[0] == hi, true);
        }
        if(!is_limit && is_num) mem[x] = res;

        return res;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(mem, -1, sizeof mem);
        for(auto& e : digits) h.insert(e);

        return dfs(digits, s, 0, true, false);
    }
};
// @lc code=end

