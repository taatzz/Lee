/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

// @lc code=start
#include <vector>

using namespace std;

// class Solution {
// public:
//     int find(int x)
//     {
//         if(x != parent[x]) // 路径压缩
//             parent[x] = find(parent[x]);
//         return parent[x];
//     }
        // 并查集维护每一个连通块的点的个数
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         parent.resize(n, 0);
//         size.resize(n, 0);

           // 初始化
//         for(int i = 0; i < n; i++)
//         {
//             parent[i] = i;
//             size[i] = 1;
//         }

//         for(int i = 0; i < edges.size(); i++)
//         {
//             int a = find(edges[i][0]), b = find(edges[i][1]);
//             if(a != b)
//             {
//                parent[a] = b; // 点a的父节点
//                size[b] += size[a]; // 父节点的连通节点 + 子节点的联通节点
//             }
//         }
//         long long res = 0;
//         for(int i = 0; i < n; i++)
//         {
//             res += n - size[find(i)]; // 当前顶点无法到达的顶点数量n减去当前联通块的顶点数量
//         }

//         return res / 2;
//     }

// private:
//     vector<int> parent;
//     vector<int> size;
// };


class Solution {
public:
    int dfs(int x)
    {
        st[x] = 1;
        int size = 1;

        for(int i : graph[x])
        {
            if(!st[i])
                size += dfs(i);
        }

        return size;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.resize(n, vector<int>(n, 0));
        st.resize(n, 0);

        for(auto e : edges)
        {
            graph[e[0]][e[1]] = 1;
            graph[e[1]][e[0]] = 1;
        }

        long long res = 0, prev = 0;
        for(int i = 0; i < n; i++)
        {
            if(!st[i])
            {
                int size = dfs(i);
                res = (long)size * prev;
                prev += res;
            }
        }

        return res;
    }

private:
    vector<vector<int> > graph;
    vector<int> st;
};



// @lc code=end

