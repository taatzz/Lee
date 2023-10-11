/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        // dp[i][j] 表示下标为i-1和j-1的两个子串的公共长度
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        // dp[i][j] 分为相同和不同，相同时dp[i][j] = dp[i-1][j-1] + 1;
        //  不相同时 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //  当前公共子串的长度由前一个字符的公共子串长度和上一个字符的公共子串决定

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

