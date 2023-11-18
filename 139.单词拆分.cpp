// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         // 单词是物品 s是背包
//         int n = s.size();
//         // 保存当前字典
//         unordered_set<string> word_set(wordDict.begin(), wordDict.end());
//         // dp[i] 表示当前长度为i时可以拆分为字典中出现的单词
//         vector<int> dp(n + 1 ,0);
//         // dp[j] = 1 [j,i]出现在字典中则dp[i] = 1 dp[i] = (dp[j],[i,j]出现在字典中)
//         dp[0] = 1;

//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 string str = s.substr(j, i - j);
//                 if(word_set.find(str) != word_set.end() && dp[j])
//                     dp[i] = 1;
//             }
//         }

//         return dp[n];
//     }
// };
// @lc code=end


class Solution {
public:
    static const int N = 20010;
    int son[N][27], idx = 0;
    int cnt[N];
    bool st[N];

    void insert(string s)
    {
        int p = 0;
        for(auto e : s)
        {
            int u = e - 'a';
            if(!son[p][u])
                son[p][u] = ++ idx;
            p = son[p][u];
        }
        cnt[p] ++;
    }

    bool dfs(string s, int x)
    {
        // 被标记说明后续无法匹配直接返回0
        if(st[x])
            return 0;
        if(x >= s.size())
            return 1;
        int p = 0;
        for(int i = x; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
            if(cnt[p]) 
            {
                if(dfs(s, i + 1)) return 1;
                // 上面的递归没有返回说明后续的字符不存在字典中，标记以实现记忆化搜索
                st[i + 1] = 1;
            }
        }
        return 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto e : wordDict)
        {
            insert(e);
        }

        return dfs(s, 0);
    }
};

