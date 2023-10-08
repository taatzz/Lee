/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 单词是物品 s是背包
        int n = s.size();
        // 保存当前字典
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        // dp[i] 表示当前长度为i时可以拆分为字典中出现的单词
        vector<int> dp(n + 1 ,0);
        // dp[j] = 1 [j,i]出现在字典中则dp[i] = 1 dp[i] = (dp[j],[i,j]出现在字典中)
        dp[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                string str = s.substr(j, i - j);
                if(word_set.find(str) != word_set.end() && dp[j])
                    dp[i] = 1;
            }
        }

        return dp[n];
    }
};
// @lc code=end

