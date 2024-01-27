/*
 * @lc app=leetcode.cn id=2492 lang=cpp
 *
 * [2492] 两个城市间路径的最小分数
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx = 0, res = INT_MAX;
    int st[N];

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void bfs()
    {
        queue<int> q;
        q.push(1);
        st[1] = 1;

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                res = min(res, w[i]);
                if(!st[j]) 
                {
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }

    int minScore(int n, vector<vector<int>>& nums) {
        memset(h, -1, sizeof h);
        for(auto& e : nums)
        {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c), add(b, a, c);
        }

        bfs();

        return res;
    }
};
// @lc code=end

