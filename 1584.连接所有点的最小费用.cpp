/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 1010, M = 1000010;

    struct Edge
    {
        int a, b, w;
        bool operator<(Edge& e)
        {
            return w < e.w;
        }
    }edges[M];
    int p[N], idx = 0;

    int find(int x)
    {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        for(int i = 0; i <= n; i++) p[i] = i;

        // 处理每一条边
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges[idx++] = { i,j,w };
            }
        }

        // 排序 + Kruskal
        sort(edges, edges + idx);

        // 一定存在一条路径，只需要添加到答案
        int res = 0;
        for(int i = 0; i < idx; i++)
        {
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            a = find(a), b = find(b);

            if(a != b)
            {
                p[a] = b;
                res += w;
            }
        }

        return res;
    }
};
// @lc code=end

