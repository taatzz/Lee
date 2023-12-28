/*
 * @lc app=leetcode.cn id=1368 lang=cpp
 *
 * [1368] 使网格图至少有一条有效路径的最小代价
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 40010;
    int h[N], e[N], ne[N], w[N], idx;
    int dist[N];
    bool st[N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    PII d[5] = { {0, 0},{0, 1},{0, -1},{1, 0},{-1, 0} };

    void add(int a, int b, int c)
    {
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    }

    int num(int x, int y, int m)
    {
        return x * m + y;
    }

    void Dijkstra()
    {
        priority_queue<PII, vector<PII>, greater<PII>> q;
        memset(dist, 0x3f,sizeof dist);
        q.push({0, 0});
        dist[0] = 0;

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
                if(dist[j] > distance)
                {
                    dist[j] = distance + w[i];
                    q.push({dist[j], j});
                }
            }
        }
    }

    int minCost(vector<vector<int>>& grid) {
        memset(h, -1, sizeof h);
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    int a = i + dx[k], b = j + dy[k];
                    if(a >= 0 && b < m && b >= 0 && b < n)
                    {
                        int x = i + d[grid[i][j]].first, y = j + d[grid[i][j]].second;
                        if(a == x && b == y) // 将二维坐标转换成一维
                            add(num(i, j, n), num(a, b, n), 0);
                        else
                            add(num(i, j, n), num(a, b, n), 1);
                    }
                }
            }
        }

        Dijkstra();

        return dist[m * n - 1];
    }
};
// @lc code=end

