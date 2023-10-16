/*
 * @lc app=leetcode.cn id=132 lang=c
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<int> > isPalindromic(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i <= 1)
                        isPalindromic[i][j] = 1;
                    else if(isPalindromic[i+1][j-1])   
                        isPalindromic[i][j] = 1;
                }
            }
        }

        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) dp[i] = i;

        for(int i = 1; i < n; i++)
        {
            if(isPalindromic[0][i])
            {
                dp[i] = 0;
                continue;
            }
            for(int j = 0; j < i; j++)
            {
                if(isPalindromic[j+1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[n-1];
    }
};
// @lc code=end

