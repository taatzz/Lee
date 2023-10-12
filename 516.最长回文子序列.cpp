// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int> >dp(n + 1, vector<int>(n + 1, 0));

        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = i; j < n ; j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i <= 1)
                    {
                        dp[i][j] = j - i + 1;
                    }
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

