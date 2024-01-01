/*
 * @lc app=leetcode.cn id=1824 lang=cpp
 *
 * [1824] 最少侧跳次数
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 1500010;
    int dist[N];
    bool st[N];
    int dx[6] = { 1,-1,0,2,-2 };
    int dy[6] = { 0,0,1,0,0 };

    int Dijkstra(vector<vector<int>>& g)
    {
        int m = g.size(), n = g[0].size();
        memset(dist, 0x3f, sizeof dist);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        dist[n] = 0;
        q.push({0, n});

        while(q.size())
        {
            auto t = q.top();
            q.pop();
            int distance = t.first, ver = t.second;
            if(st[ver]) continue;
            st[ver] = true;

            int x = ver / n, y = ver % n;
            if(y == n - 1) return distance;

            for(int i = 0; i < 6; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if(a >= 0 && a < m && b >= 0 && b < n && g[a][b] != 1)
                {
                    int j = a * n + b;
                    int w = 0;
                    if(a == x + 1 || a == x - 1 || a == x + 2 || a == x - 2) w = 1;
                    if(dist[j] > distance + w)
                    {
                        dist[j] = distance + w;
                        q.push({dist[j], j});
                    }
                }
            }
        }
        return -1;
    }

    int minSideJumps(vector<int>& nums) {
        int m = nums.size();
        vector<vector<int>> g(3, vector<int>(m, 0));
        for(int i = 0; i < m; i++)
            if(nums[i]) g[nums[i] - 1][i] = 1;

        return Dijkstra(g);
    }
};
// @lc code=end

