/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

// 二分答案
// class Solution {
// public:
//     typedef pair<int, int> PII;
//     static const int N = 110;
//     // int dist[N][N];
//     bool st[N][N];
//     int dx[4] = { 1,0,-1,0 };
//     int dy[4] = { 0,1,0,-1 };

//     bool bfs(vector<vector<int>>& g, int x)
//     {
//         memset(st, 0, sizeof st);
//         int m = g.size(), n = g[0].size();
//         queue<PII> q;
//         st[0][0] = 1;
//         q.push({0, 0});

//         while(q.size())
//         {
//             auto t = q.front();
//             q.pop();

//             for(int i = 0; i < 4; i++)
//             {
//                 int a = t.first + dx[i], b = t.second + dy[i];
//                 if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b] && abs(g[a][b] - g[t.first][t.second]) <= x)
//                 {
//                     q.push({a, b});
//                     st[a][b] = 1;
//                 }
//             }
//         }

//         return st[m - 1][n - 1];
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m = heights.size(), n = heights[0].size();
//         int l = 0, r = 999999;

//         while(l < r)
//         {
//             int mid = (l + r) >> 1;
//             if(bfs(heights, mid)) r = mid;
//             else l = mid + 1;
//         }


//         return l;
//     }
// };
// @lc code=end

// Kruskal
class Solution {
public:
    static const int N = 20010;
    struct Edge
    {
        int a, b, w;
        bool operator<(Edge& e)
        {
            return w < e.w;
        }
    }edges[N];
    int p[N], idx = 0;

    int find(int x)
    {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        for(int i = 1; i < m * n; i++) p[i] = i;

        // 建图 将二维矩阵的点转换成图中的点权值为高度差
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j + 1 < n)
                {
                    int a = i * n + j, b = i * n + j + 1;
                    int w = abs(heights[i][j] - heights[i][j + 1]);
                    edges[idx++] = { a,b,w };
                }
                if(i + 1 < m)
                {
                    int a = i * n + j, b = (i + 1) * n + j;
                    int w = abs(heights[i][j] - heights[i + 1][j]);
                    edges[idx++] = { a,b,w };
                }
            }
        }

        sort(edges, edges + idx);
        // 起点和终点
        int start = 0, end = (m - 1) * n + n - 1;

        for(int i = 0; i < idx; i++)
        {
            auto t = edges[i];
            int a = t.a, b = t.b, w = t.w;
            a = find(a), b = find(b);
            if(a != b)
            {
                p[a] = b;
            }
            // 连通说明该边就是最短路中最大权值的边
            if(find(start) == find(end)) return w;
        }

        return 0;
    }
};