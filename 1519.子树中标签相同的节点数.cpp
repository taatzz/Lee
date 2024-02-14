/*
 * @lc app=leetcode.cn id=1519 lang=cpp
 *
 * [1519] 子树中标签相同的节点数
 */

// @lc code=start
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    int cnt[N][26];
    bool st[N];
    string _s;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int u)
    {
        st[u] = 1;
        cnt[u][_s[u] - 'a'] += 1;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            char c = _s[j];
            if(!st[j]) 
            {
                dfs(j);
                for(int i = 0; i < 26; i++) cnt[u][i] += cnt[j][i];
            }
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        memset(h, -1, sizeof h);
        _s = s;

        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b);
            add(b, a);
        }
        
        dfs(0);
        vector<int> res(n);
        for(int i = 0; i < n; i++)
            res[i] = cnt[i][s[i] - 'a'];

        return res;
    }
};
// @lc code=end

