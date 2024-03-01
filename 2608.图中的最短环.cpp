/*
 * @lc app=leetcode.cn id=2608 lang=cpp
 *
 * [2608] 图中的最短环
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int h[N], e[N * 2], ne[N * 2], dist[N], idx;
    bool st[N];
    int res = INT_MAX;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int bfs(int u)
    {
        memset(dist, -1, sizeof dist);
        dist[u] = 0;
        queue<pair<int, int>> q;
        q.push({u, -1});
        st[u] = true;
        int cnt = INT_MAX;

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = h[t.first]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(dist[j] < 0)
                {
                    dist[j] = dist[t.first] + 1;
                    q.push({j, t.first});
                }
                else if(j != t.second)
                    cnt = min(cnt, dist[t.first] + dist[j] + 1);
            }
        }

        return cnt;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        for(int i = 0; i < n; i++)
        {
            if(!st[i])
            {
                int cnt = bfs(i);
                res = min(res, cnt);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

