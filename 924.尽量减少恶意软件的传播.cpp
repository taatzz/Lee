/*
 * @lc app=leetcode.cn id=924 lang=cpp
 *
 * [924] 尽量减少恶意软件的传播
 */

// @lc code=start
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 310;
    bool st[N];
    int idx = 0, a[N];
    unordered_set<int> h[N];
    unordered_set<int> t;

    int dfs(vector<vector<int>>& g, int x)
    {
        h[idx].insert(x);
        st[x] = true;
        int cnt = 0;
        if(t.find(x) != t.end()) cnt++;

        for(int i = 0; i < g[x].size(); i++)
        {   
            int j = g[x][i];
            if(!st[i] && j == 1)
            {
                cnt += dfs(g, i);
            }
        }

        return cnt;
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        for(auto& e : initial) t.insert(e);

        int n = graph.size(), sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(!st[i])
            {
                int cnt = dfs(graph, i);
                a[idx] = cnt;
                if(a[idx] == 0) sum += h[idx].size();
                idx++;
            }
        }

        int res = 0, mx = -1;
        for(int i = 0; i < initial.size(); i++)
        {
            int cnt = sum;
            for(int j = 0; j < idx; j++)
            {
                if(h[j].find(initial[i]) != h[j].end())
                {
                    if(a[j] - 1 == 0) cnt += h[j].size();
                }
            }
            if(cnt > mx) res = initial[i], mx = cnt;
            else if(cnt == mx) res = min(res, initial[i]);
        }

        return res;
    }
};
// @lc code=end

