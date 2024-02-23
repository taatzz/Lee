/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 *
 * [2039] 网络空闲的时刻
 */

// @lc code=start
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N* 2], ne[N * 2], dist[N], idx;
    bool st[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void bfs()
    {
        queue<int> q;
        q.push(0);
        st[0] = true;
        dist[0] = 0;

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                    dist[j] = dist[t] + 1;
                }
            }
        }
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& nums) {
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }
        bfs();

        int n = nums.size();
        int res = 0;

        for(int i = 1; i < n; i++)
        {
            int time = dist[i] * 2;
            int x = time <= nums[i] ? time : (time - 1) / nums[i] * nums[i] + time;
            res = max(res, x);
        }

        return res + 1;
    }
};
// @lc code=end

