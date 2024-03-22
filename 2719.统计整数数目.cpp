/*
 * @lc app=leetcode.cn id=2719 lang=cpp
 *
 * [2719] 统计整数数目
 */

// @lc code=start
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int mn, mx;
    static const int N = 10010, mod = 1e9 + 7;
    int mem[N][410];

    int dfs(string s, int x, int sum, bool is_limit)
    {
        int n = s.size();
        if(x == n)
        {
            if(sum >= mn && sum <= mx) return 1;
            else return 0;
        }
        if(!is_limit && mem[x][sum] != -1) return mem[x][sum];

        int hi = (is_limit ? s[x] - '0' : 9);
        int res = 0;
        for(int i = 0; i <= hi; i++)
        {
            res = (res + dfs(s, x + 1, sum + i, is_limit && i == hi)) % mod;
        }
        if(!is_limit) mem[x][sum] = res;

        return res;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        mn = min_sum, mx = max_sum;

        memset(mem, -1, sizeof mem);
        int a = dfs(num2, 0, 0, true);
        memset(mem, -1, sizeof mem);
        int b = dfs(num1, 0, 0, true);
        int res = a - b + mod;

        int sum = 0;
        for(char c : num1) sum += c - '0';

        res += min_sum <= sum && sum <= max_sum;

        return res % mod;
    }
};
// @lc code=end

