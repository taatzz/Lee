/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();

        // dp[i][j] dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。
        vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));
        // 两个字符相等时 dp[i][j] = dp[i-1][j-1] + 1;
        // 两个字符不相等时当前的公共长度为dp[i][j] = dp[i][j-1];

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == s[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = dp[i][j-1];
            }
        }

        return dp[m][n] == m;
    }
};
// @lc code=end

