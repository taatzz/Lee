/*
 * @lc app=leetcode.cn id=2467 lang=cpp
 *
 * [2467] 树上最大得分和路径
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    bool st[N];
    int t_b[N];
    vector<int> w;
    int res = INT_MIN;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    bool dfs1(int u, int d)
    {   
        if(u == 0)
        {
            t_b[0] = d;
            return 1;
        }
        st[u] = 1;
        bool flag = false;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                if(dfs1(j, d + 1)) 
                {
                    t_b[u] = min(t_b[u], d);
                    flag = true;
                }
            }
        }

        return flag;
    }

    void dfs2(int u, int d, int sum)
    {

        st[u] = 1;
        if(d < t_b[u]) sum += w[u];
        else if(d == t_b[u]) sum += w[u] / 2;

        bool flag = false;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                flag = true;
                dfs2(j, d + 1, sum);
            }
        }

        if(!flag) res = max(res, sum);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        memset(t_b, 0x3f, sizeof t_b);
        memset(h, -1, sizeof h);
        w = amount;
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        dfs1(bob, 0);
        memset(st, 0, sizeof st);
        dfs2(0, 0, 0);

        return res;
    }
};
// @lc code=end

