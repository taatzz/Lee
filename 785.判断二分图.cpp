/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 110, M = 10010;
    int h[N], e[M], ne[M], idx = 0;
    int color[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    bool dfs(int u, int c)
    {
        color[u] = c;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!color[j])
            {
                if(!dfs(j, 3 - c)) return false;
            }
            else if(color[j] == c) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        memset(h, -1, sizeof h);
        int n = graph.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                add(i, graph[i][j]);
            }
        }
        
        bool flag = 1;
        for(int i = 0; i < n; i++)
        {
            if(!color[i])
            {
                if(!dfs(i, 1))
                {
                    flag = 0;
                    break;
                }
            }
        }

        return flag;
    }
};
// @lc code=end

