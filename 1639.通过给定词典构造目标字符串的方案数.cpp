/*
 * @lc app=leetcode.cn id=1639 lang=cpp
 *
 * [1639] 通过给定词典构造目标字符串的方案数
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>  

using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = target.size(), mod = 1e9 + 7;
        vector<vector<int>> mem(words[0].size() + 1, vector<int>(m + 1, -1));
        vector<vector<int>> cnt(words[0].size() + 1, vector<int>(26));
        
        for(auto& e : words)
        {
            for(int j = 0; j < e.size(); j++)
            {
                cnt[j][e[j] - 'a']++;
            }
        }

        // 用第i列的字母去匹配target的第j个字母
        function<int(int, int)> dfs = [&](int i, int j)->int
        {
            if(j == m) return 1;
            if(i == words[0].size()) return 0;
            if(mem[i][j] != -1) return mem[i][j];

            long res = 0;
            // 不用第i列匹配
            res = (res + dfs(i + 1, j)) % mod;

            // 使用第i列那么就把全部可以匹配的都进行匹配
            // for(int k = 0; k < n; k++)
            // {
            //     if(words[k][i] == target[j])
            //         res += dfs(i + 1, j + 1);
            // }
            char c = target[j];
            if(cnt[i][c - 'a'] > 0)
                res = (res + ((long)cnt[i][c - 'a'] * dfs(i + 1, j + 1))) % mod;

            return mem[i][j] = res;
        };

        return dfs(0, 0) % mod;
    }
};
// @lc code=end

