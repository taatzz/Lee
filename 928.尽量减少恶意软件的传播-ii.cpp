/*
 * @lc app=leetcode.cn id=928 lang=cpp
 *
 * [928] 尽量减少恶意软件的传播 II
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> h;
    int bad;
    static const int N = 310;
    bool st[N];

    int dfs(vector<vector<int>>& g, int x)
    {
        int cnt = 1;
        st[x] = 1;
        if(h.find(x) != h.end()) bad++;

        for(int i = 0; i < g[x].size(); i++)
        {   
            if(!st[i] && g[x][i] == 1) 
            {
                cnt += dfs(g, i);
            }
        }

        return cnt;
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        for(auto& e : initial) h.insert(e);

        int res = INT_MAX, mx = 0;
        for(auto& e : initial)
        {
            memset(st, 0, sizeof st);
            int sum = 1;
            for(int i = 0; i < graph[e].size(); i++)
            {
                if(st[i]) continue;
                bad = 0;
                st[e] = 1;
                int cnt = dfs(graph, i);
                if(bad == 0) sum += cnt;
            }
            if(sum > mx) res = e, mx = sum;
            else if(sum == mx) res = min(res, e);
        }

        return res;
    }
};
// @lc code=end

