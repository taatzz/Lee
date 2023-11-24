/*
 * @lc app=leetcode.cn id=2685 lang=cpp
 *
 * [2685] 统计完全连通分量的数量
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 60, M = 1300;
    int h[N], e[M], ne[M], idx = 0;
    bool st[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int x, int& a, int & v)
    {
        st[x] = 1;
        v++;
        // 无向图每个点的边都会被遍历两边
        for(int i = h[x]; i != -1; i = ne[i])
        {
            a++;
            int j = e[i];
            if(!st[j])
            {
                dfs(j, a, v);
            }
        }
    }

    // 无向完全图每个顶点都有边相连，e = v * (v - 1) / 2;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for(auto e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(!st[i])
            {
                int e = 0, v = 0;
                dfs(i, e, v);
                // 每条边统计了两次则 e = v * (v - 1)
                if(e == v * (v - 1))
                    res++;
            }
        }

        return res;
    }
};
// @lc code=end

