/*
 * @lc app=leetcode.cn id=2290 lang=cpp
 *
 * [2290] 到达角落需要移除障碍物的最小数目
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 400010;
    int h[N], ne[N], e[N], w[N], idx;
    int dist[N];
    bool st[N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void Dijkstra()
    {
        priority_queue<PII, vector<PII>, greater<PII>> q;
        memset(dist, 0x3f, sizeof dist);
        dist[0] = 0;
        q.push({0, 0});

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

    int minimumObstacles(vector<vector<int>>& grid) {
        memset(h, -1, sizeof h);
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    int a = i + dx[k], b = j + dy[k];
                    if(a >= 0 && a < m && b >= 0 && b < n)
                    {
                        int w = 0;
                        if(grid[a][b] == 1) w = 1;
                        add(i * n + j, a * n + b, w);
                    }
                }
            }
        }

        Dijkstra();


        return dist[(m - 1) * n + n - 1];
    }
};
// @lc code=end

