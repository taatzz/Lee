/*
 * @lc app=leetcode.cn id=2192 lang=cpp
 *
 * [2192] 有向无环图中一个节点的所有祖先
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 2010;
    int h[N], e[N], ne[N], idx;
    int in[N];
    unordered_map<int, set<int>> res;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void topsort(int n)
    {
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!in[i]) q.push(i);

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                for(auto& el : res[t]) res[j].insert(el);
                res[j].insert(t);
                if(--in[j] == 0) q.push(j);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b);
            in[b]++;
        }

        topsort(n);
        vector<vector<int>> ans(n);
        for(auto& [k, e] : res)
        {
            for(auto& x : e)
            {
                ans[k].push_back(x);
            }
        }

        return ans;
    }
};
// @lc code=end

