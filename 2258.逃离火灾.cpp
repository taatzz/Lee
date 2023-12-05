/*
 * @lc app=leetcode.cn id=2258 lang=cpp
 *
 * [2258] 逃离火灾
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 310;
    typedef pair<int, int> PII;
    int dist[N][N]; // 保存火蔓延的时间
    bool st[N][N];
    int dist_hum[N][N]; // 保存每个人到点的时间
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    queue<PII> q;

    void bfs(vector<vector<int>>& g)
    {
        int m = g.size(), n = g[0].size();
    
        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];

                if(a < 0 || a >= m || b < 0 || b >= n) continue;
                if(g[a][b] == 2) continue;
                if(st[a][b]) continue;

                dist[a][b] = dist[t.first][t.second] + 1;
                st[a][b] = 1;
                q.push({a, b});
            }
        }
    }

    bool check(vector<vector<int>>& g, int x)
    {
        memset(st, 0, sizeof st);
        memset(dist_hum, 0, sizeof dist_hum);
        queue<PII> q;
        int m = g.size(), n = g[0].size();

        if(x > dist[0][0]) return false;

        // 必须使用dist_hum数组直接计算时间的话就算多了（如果当前路无法到达，时间是不应该计算的）
        dist_hum[0][0] = x;
        q.push({0, 0});
        st[0][0] = 1;

        while(q.size())
        {
            auto t = q.front();
            q.pop();
            int distance = dist_hum[t.first][t.second];

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];

                if(a < 0 || a >= m || b < 0 || b >= n) continue;
                if(st[a][b]) continue;
                if(g[a][b] == 2) continue;
                if(dist[a][b] <= distance + 1) 
                {
                    // 火和人同时到达终点此时人是无敌的人已经走到了
                    if(a == m - 1 && b == n - 1 && dist[a][b] == distance + 1) return 1;
                    continue;
                }
                st[a][b] = 1;
                q.push({a, b});
                dist_hum[a][b] = distance + 1;
            }
        }

        return st[m - 1][n - 1];
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dist, 0x3f, sizeof dist);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    st[i][j] = 1;
                    dist[i][j] = 0;
                }
            }

        // 第一遍bfs计算火的蔓延时间
        bfs(grid);

        // 后续二分查找
        int l = -1, r = 1e9;
        while(l < r)
        {
            int mid = (l + r + 1) / 2;

            if(check(grid, mid)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

