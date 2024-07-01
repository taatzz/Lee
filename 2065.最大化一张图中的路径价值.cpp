/*
 * @lc app=leetcode.cn id=2065 lang=cpp
 *
 * [2065] 最大化一张图中的路径价值
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 2010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
    bool st[N];
    int res = 0, k;
    vector<int> t;

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int u, int time, int sum)
    {
        if(u == 0)
            res = max(res, sum);
        
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(time + w[i] > k) continue;
            if(st[j]) dfs(j, time + w[i], sum);
            else
            {
                st[j] = 1;
                dfs(j, time + w[i], sum + t[j]);
                st[j] = 0;
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        t = values;
        k = maxTime;

        for(auto& e : edges)
        {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c);
            add(b, a, c);
        }
        st[0] = 1;
        dfs(0, 0, values[0]);

        return res;
    }
};
// @lc code=end

