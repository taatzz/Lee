/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达节点
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 3010;
    int g[N][N], dist[N];
    bool st[N];

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        memset(g, 0x3f, sizeof g);
        memset(dist, 0x3f, sizeof dist);
        for(auto e : edges)
        {
            int a = e[0], b = e[1], c = e[2] + 1;
            g[b][a] = g[a][b] = min(g[a][b], c);
        }

        dist[0] = 0;
        for(int i = 0; i < n; i++)
        {
            int t = -1;
            for(int j = 0; j < n; j++)
            {
                if(!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;
            }

            st[t] = true;
            for(int j = 0; j < n; j++)
                dist[j] = min(dist[j], dist[t] + g[t][j]);
        }


        int res = 0;
        for(int i = 0; i < n; i++)
            if(dist[i] <= maxMoves) 
                res++;
        
        for(auto e : edges)
        {
            int a = e[0], b = e[1], c = e[2];
            int c1 = max(0, maxMoves - dist[a]), c2 = max(0, maxMoves - dist[b]);
            res += min(c, c1 + c2);
        }

        return res;
    }
};
// @lc code=end

