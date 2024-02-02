/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 *
 * [2359] 找到离给定两个节点最近的节点
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N], ne[N], idx = 0;
    bool st[N];
    int dist1[N], dist2[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int u, int t)
    {
        st[u] = 1;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(st[j]) continue;
            if(t == 1) dist1[j] = dist1[u] + 1;
            else dist2[j] = dist2[u] + 1;
            dfs(j, t);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        memset(h, -1, sizeof h);
        memset(dist1, -1, sizeof dist1);
        memset(dist2, -1, sizeof dist2);

        for(int i = 0; i < n; i++)
        {
            if(edges[i] == -1) continue;
            int a = i, b = edges[i];
            add(a, b);
        }

        dist1[node1] = 0;
        dist2[node2] = 0;
        dfs(node1, 1);
        memset(st, 0, sizeof st);
        dfs(node2, 2);


        int res = -1, d = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(dist1[i] == -1 || dist2[i] == -1) continue;
            int t = max(dist1[i], dist2[i]);
            if(t < d) 
            {
                res = i;
                d = t;
            }
        }
        
        return res;
    }
};
// @lc code=end

