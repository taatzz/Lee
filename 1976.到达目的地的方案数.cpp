/*
 * @lc app=leetcode.cn id=1976 lang=cpp
 *
 * [1976] 到达目的地的方案数
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 210;
    int g[N][N];
    long dist[N];
    bool st[N];
    int in[N];

    void Dijkstra(int n)
    {
        memset(dist, 0x3f, sizeof dist);
        dist[0] = 1;

        for(int i = 0; i < n; i++)
        {
            int t = -1;
            for(int j = 0; j < n; j++)
            {
                if(!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;
            }

            st[t] = 1;
            for(int j = 0; j < n; j++)
            {
                if(g[t][j] == 0) continue;
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        int size = roads.size();

        for(auto e : roads)
        {
            int a = e[0], b = e[1], c = e[2];
            g[a][b] = g[b][a] = c;
        }

        Dijkstra(n);


        for(auto e : roads)
        {
            int a = e[0], b = e[1], c = e[2];
            g[a][b] = g[b][a] = 0;
            if(dist[a] + c == dist[b])
            {
                g[a][b] = c;
                in[b]++;
            }
            else if(dist[b] + c == dist[a])
            {
                g[b][a] = c;
                in[a]++;
            }
        }

        int mod = 1e9 + 7;
        vector<int> f(n, 0);
        f[0] = 1;

        queue<int> q;

        for(int i = 0; i < n; i++)
            if(!in[i]) q.push(i);

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = 0; i < n; i++)
            {
                if(g[t][i] == 0) continue;
                f[i] += f[t];
                f[i] %= mod;
                if(-- in[i] == 0) q.push(i);
            }
        }

        return f[n - 1];
    }
};
// @lc code=end

