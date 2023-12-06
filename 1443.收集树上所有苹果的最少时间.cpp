/*
 * @lc app=leetcode.cn id=1443 lang=cpp
 *
 * [1443] 收集树上所有苹果的最少时间
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    bool st[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    // 1.子树根节点和所有子节点都没有苹果则返回0
    // 2.其余时候如果当前树的根节点或者子节点有苹果都返回chid + 2
    int dfs(int x, vector<bool>& a, int cost)
    {
        st[x] = 1;

        int child = 0;
        for(int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(st[j]) continue;
            child += dfs(j, a, 2);
        }

        if(!a[x] && child == 0) return 0;

        return child + cost;// 子节点的开销 + 走到当前节点的开销
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        memset(h, -1, sizeof h);
        for(auto e : edges)
        {
            add(e[0], e[1]), add(e[1], e[0]);
        }

        // 0 节点的开销时0，其余都是2
        return dfs(0, hasApple, 0);
    }
};
// @lc code=end

