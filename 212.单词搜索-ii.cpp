/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_set<string> t;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    typedef pair<int, int> pii;
    bool st[15][15];
    static const int N = 300010;
    int son[N][26], idx, cnt[N];

    void dfs(vector<vector<char>>& g, int x, int y, string tmp, int len)
    {
        int m = g.size(), n = g[0].size();
        t.insert(tmp);
        if(tmp.size() == len) return;

        st[x][y] = 1;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b])
            {
                dfs(g, a, b, tmp + g[a][b], len);
            }   
        }
        st[x][y] = 0;
    }

    void insert(string s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u])
                son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }

    bool query(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return cnt[p];
    }

    vector<string> findWords(vector<vector<char>>& g, vector<string>& words) {
        int m = g.size(), n = g[0].size();
        unordered_set<char> a[11];
        for(auto e : words)
        {
            if(a[e.size()].count(e[0])) continue;
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(g[i][j] != e[0]) continue;
                    string t;
                    t += g[i][j];
                    dfs(g, i, j, t, e.size());
                }
            }
            a[e.size()].insert(e[0]);
        }

        vector<string> res;
        for(auto& e : t) 
        {
            insert(e);
        }
        for(auto& e : words)
        {
            if(query(e)) res.push_back(e);
        }

        return res;
    }
};
// @lc code=end

