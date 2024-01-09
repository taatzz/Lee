/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
    bool st[N];
    int dist[N];
    int res;

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    // void dfs(int u, int t)
    // {
    //     st[u] = true;

    //     for(int i = h[u]; i != -1; i = ne[i])
    //     {
    //         int j = e[i];
    //         if(st[j]) continue;
    //         dfs(j, t + w[i]);
    //     }

    //     res = max(res, t);
    // }

    void bfs(int u)
    {
        queue<int> q;
        q.push(u);
        st[u] = true;

        dist[u] = 0;

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(st[j]) continue;

                dist[j] = dist[t] + w[i];
                st[j] = true;
                q.push(j);

                res = max(res, dist[j]);
            }
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        memset(h, -1, sizeof h);
        for(int i = 0; i < manager.size(); i++)
        {
            if(manager[i] == -1) continue;
            int a = i, b = manager[i], c = informTime[manager[i]];

            add(a, b, c), add(b, a, c);
        }

        // dfs(headID, 0);
        bfs(headID);

        return res;
    }
};
// @lc code=end

