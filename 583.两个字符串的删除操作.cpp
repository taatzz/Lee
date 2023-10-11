/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        // dp[i][j] 以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数。
        vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

