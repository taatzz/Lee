/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n = s.size();

        vector<vector<int> >dp(n, vector<int>(n, 0));
        int cnt = 0, left = 0, right = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i <= 1)
                        dp[i][j] = true;
                    else if(dp[i+1][j-1])
                        dp[i][j] = true;
                }
                if(dp[i][j] && i - j > 1)
                {
                    cnt = j - i;
                    left = i;
                    right = j;
                }
            }
        }

        return s.substr(left, right - left + 1);
    }
};
// @lc code=end

