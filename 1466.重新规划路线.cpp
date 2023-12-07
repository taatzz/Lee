/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 50010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
    bool st[N];
    int res = 0;

    void add(int a,int b,int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void bfs()
    {
        queue<int> q;
        q.push(0);
        st[0] = 1;

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(st[j]) continue;
                if(w[i] == 1)
                    res++;
                q.push(j);
                st[j] = 1;
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        memset(h, -1, sizeof h);
        for(auto e : connections)
        {
            int a = e[0], b = e[1];
            add(a, b, 1), add(b, a, 0);
        }

        bfs();

        return res;
    }
};
// @lc code=end

