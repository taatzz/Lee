/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1 ,0);

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < wordDict.size(); j++)
            {
                if(i - wordDict[j].size() >= 0)
                    dp[i] = dp[i - wordDict[j].size()] + wordDict[j].size();
            }
        }

        return dp[n] == n;
    }
};
// @lc code=end

