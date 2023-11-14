/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std; 

class Solution {
public:
    static const int N = 110, M = 10010;
    typedef pair<int, int> PII;
    int h[N], e[M], ne[M], w[M], dist[N], idx = 0;
    bool st[N];

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void Dijkstra(int x)
    {
        memset(dist, 0x3f, sizeof dist);
        memset(st, 0, sizeof st);
        priority_queue<PII, vector<PII>, greater<PII> > q;
        dist[x] = 0;
        q.push({dist[x], x});

        while(q.size())
        {
            auto t = q.top();
            q.pop();
            int distance = t.first, ver = t.second;
            if(st[ver]) continue;
            st[ver] = 1;

            for(int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(dist[j] > distance + w[i])
                {
                    dist[j] = distance + w[i];
                    q.push({dist[j], j});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        memset(h, -1, sizeof h);
        for(auto e : edges)
        {
            int a = e[0], b = e[1], w = e[2];
            add(a, b, w), add(b, a, w);
        }
        
        int prev = n, res = 0;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            // Dijkstra 统计每一条边到每一点的距离
            Dijkstra(i);

            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(dist[j] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= prev)
            {
                res = i;
                prev = cnt;
            }
        }

        return res;
    }
};
// @lc code=end

