/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 30010;
    int son[N][26], idx, cnt[N];

    static bool cmp(string& a, string& b)
    {
        return a.size() < b.size();
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }

    bool query(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size() - 1; i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
            if(!cnt[p]) return false;
        }

        return true;
    }

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        string res = "";
        for(int i = 0; i < words.size(); i++)
        {
            if(query(words[i])) 
            {
                if(res == "") res = words[i];
                else 
                {
                    if(res.size() == words[i].size()) res = min(res, words[i]);
                    else res = words[i];
                }
            }
            insert(words[i]);
        }

        return res;
    }
};
// @lc code=end

