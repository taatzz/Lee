/*
 * @lc app=leetcode.cn id=2101 lang=cpp
 *
 * [2101] 引爆最多的炸弹
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 10010;
    int h[N], e[N], ne[N], idx;
    bool st[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int dfs(int u)
    {
        int res = 1;
        st[u] = true;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
                res += dfs(j);
        }

        return res;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        memset(h, -1, sizeof h);
        int n = bombs.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                int x1 = bombs[i][0], y1 = bombs[i][1];
                int x2 = bombs[j][0], y2 = bombs[j][1];
                long long distance = (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);
                if(distance <= (long long)bombs[i][2] * bombs[i][2]) add(i, j);
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            memset(st, 0, sizeof st);
            res = max(res, dfs(i));
        }

        return res;
    }
};
// @lc code=end

