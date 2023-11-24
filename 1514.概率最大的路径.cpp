/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<double, int> PII;
    static const int N = 20010;
    int h[N], e[N * 4 ], ne[N * 4], idx = 0;
    double w[N * 4];
    bool st[N];
    double dist[N];

    void add(int a, int b, double c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void Dijkstra(int n, int x)
    {
        dist[x] = 1.00;
        // 大顶堆
        priority_queue<PII, vector<PII>, less<PII> > q;
        q.push({1.00, x});

        while(q.size())
        {
            auto t = q.top();
            q.pop();
            double d = t.first;
            int ver = t.second;
            if(st[ver]) continue;
            st[ver] = 1;

            for(int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(dist[j] < d * w[i])
                {
                    dist[j] = d * w[i];
                    q.push({dist[j], j});
                }
            }
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        memset(h, -1, sizeof h);

        for(int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0], b = edges[i][1];
            double c = succProb[i];
            add(a, b, c), add(b, a, c);   
        }

        Dijkstra(n, start_node);

        return dist[end_node];
    }
};
// @lc code=end

