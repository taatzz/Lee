/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <set>

using namespace std;

class WordFilter {
public:
    static const int N = 70010;
    int pre[N][26], suf[N][26];
    int pre_idx = 0, suf_idx = 0;
    unordered_map<int, set<int>> h_pre, h_suf;

    void pre_insert(string& s, int x)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!pre[p][u]) pre[p][u] = ++ pre_idx;
            h_pre[p].insert(x);
            p = pre[p][u];
        }

        h_pre[p].insert(x);
    }

    void suf_insert(string& s, int x)
    {
        int p = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int u = s[i] - 'a';
            if(!suf[p][u]) suf[p][u] = ++ suf_idx;
            h_suf[p].insert(x);
            p = suf[p][u];
        }

        h_suf[p].insert(x);
    }

    int find(string& s1, string& s2)
    {
        int p1 = 0;
        for(int i = 0; i < s1.size(); i++)
        {
            int u = s1[i] - 'a';
            if(!pre[p1][u]) return -1;
            p1 = pre[p1][u];
        }

        int p2 = 0;
        for(int i = s2.size() - 1; i >= 0; i--)
        {
            int u = s2[i] - 'a';
            if(!suf[p2][u]) return -1;
            p2 = suf[p2][u];
        }

        for(auto it = h_suf[p2].rbegin(); it != h_suf[p2].rend(); it++)
        {
            if(h_pre[p1].find(*it) != h_pre[p1].end()) return *it;
        }

        return -1;
    }

    WordFilter(vector<string>& words) {
        int p = 0;
        memset(pre, 0, sizeof pre);
        memset(suf, 0, sizeof suf);

        for(int i = 0; i < words.size(); i++)
        {
            pre_insert(words[i], i);
            suf_insert(words[i], i);
        }
    }
    
    int f(string pref, string suff) {
        return find(pref, suff);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end

