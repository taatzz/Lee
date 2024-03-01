/*
 * @lc app=leetcode.cn id=2360 lang=cpp
 *
 * [2360] 图中的最长环
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N], ne[N], in[N], idx;
    bool st[N];
    int res = -1;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void top_sort(int n)
    {
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0) q.push(i);
        }

        while(q.size())
        {
            int t = q.front();
            q.pop();
            st[t] = 1;

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(-- in[j] == 0)
                {
                    q.push(j);
                }
            }
        }
    }

    int dfs(int u)
    {
        int cnt = 1;
        st[u] = 1;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                cnt += dfs(j);
            }
        }

        return cnt;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        memset(h, -1, sizeof h);
        for(int i = 0; i < n; i++)
        {
            int a = edges[i];
            if(a == -1) continue;
            add(i, a);
            in[a]++;
        }
        top_sort(n);

        for(int i = 0; i < n; i++)
        {
            if(!st[i])
            {
                int cnt = dfs(i);
                res = max(cnt, res);
            }
        }

        return res;
    }
};
// @lc code=end

