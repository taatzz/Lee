/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        int mod = 1e9 + 7;

        // f[i][j] 表示s的前i个字符和t的前j个字符匹配的方案数
        // 两种情况，第i个字符不参与匹配那么方案数就是f[i - 1][j];
        //           第i个字符参与匹配，前提是s[i] == t[j]  f[i][j] += f[i - 1][j];
        //  f[i][j] = f[i - 1][j] + f[i - 1][j - 1] % mod; 
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for(int i = 0; i <= m; i++) f[i][0] = 1;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                f[i][j] = f[i - 1][j];
                if(s[i - 1] == t[j - 1])
                    f[i][j] += (0LL + f[i - 1][j - 1]) % mod;
            }
        }

        return f[m][n];
    }   
};
// @lc code=end

