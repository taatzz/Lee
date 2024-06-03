/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */

// @lc code=start
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        int cnt[n][2][26];
        memset(cnt, 0, sizeof cnt);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                int u = words[i][j] - 'a';
                cnt[i][j % 2][u]++;
            }
        }

        int res = 0;
        vector<bool> st(n);
        for(int i = 0; i < n; i++)
        {
            if(!st[i]) res++;
            else continue;
            for(int j = i + 1; j < n; j++)
            {
                if(!st[j])
                {
                    bool flag = 1;
                    for(int k = 0; k < 26; k++)
                    {
                        if(cnt[i][0][k] != cnt[j][0][k]) flag = 0;
                        if(cnt[i][1][k] != cnt[j][1][k]) flag = 0;
                    }
                    if(flag) st[j] = 1;
                }
            }
        }

        return res;
    }
};
// @lc code=end

