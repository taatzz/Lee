/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 20;
    int dist[N][N];
    bool st[N][N];
    queue<PII> q;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void bfs(vector<vector<int>>& g)
    {
        int m = g.size(), n = g[0].size();
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;

            for(int i = 0; i < 4; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if(a >= 0 && a < m && b >= 0 && b < n && g[a][b] == 1 && !st[a][b])
                {
                    st[a][b] = true;
                    dist[a][b] = dist[x][y] + 1;
                    q.push({a, b});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                    st[i][j] = true;
                }
        }

        bfs(grid);
        int res = 0, flag = true;;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && !st[i][j])
                {
                    flag = false;
                    break;
                }
                res = max(res, dist[i][j]);
            }
        }

        return flag ? res : -1;
    }
};
// @lc code=end

