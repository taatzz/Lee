/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 510;
    bool st[N][N];
    int dist[N][N];
    int res = INT_MAX;
    queue<pair<int, int>> q;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void dfs(vector<vector<int>>& g, int i, int j)
    {
        int m = g.size(), n = g[0].size();
        st[i][j] = 1;
        q.push({i, j});
        dist[i][j] = 0;

        for(int k = 0; k < 4; k++)
        {
            int a = i + dx[k], b = j + dy[k];
            if(a >= 0 && a < m && b >= 0 && b < n && g[a][b] == 1 && !st[a][b])
            {
                dfs(g, a, b);
            }
        }
    }

    void bfs(vector<vector<int>>& g)
    {
        int m = g.size(), n = g[0].size();

        while(q.size())
        {
            int len = q.size();
            while(len --)
            {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;

                for(int k = 0; k < 4; k++)
                {
                    int a = x + dx[k], b = y + dy[k];
                    if(a >= 0 && a < m && b >= 0 && b < n && dist[a][b] == -1)
                    {
                        dist[a][b] = dist[x][y] + 1;
                        q.push({a, b});
                        if(g[a][b] == 1 && !st[a][b])
                        {
                            res = min(res, dist[a][b] - 1);
                        }
                    }
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dist, -1, sizeof dist);

        for(int i = 0; i < m; i++)
        {
            bool flag = false;
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] && !st[i][j])
                {
                    dfs(grid, i, j);
                    flag = true;
                }
                if(flag) break;
            }
            if(flag) break;
        }

        bfs(grid);

        return res;
    }
};
// @lc code=end

