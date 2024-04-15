/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */

// @lc code=start
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    bool st[110][110];
    typedef pair<int, int> pii;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void bfs(vector<vector<int>>& g, int x, int y)
    {
        queue<pii> q;
        q.push({x, y});
        st[x][y] = 1;
        int n = g.size();

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < n && b >= 0 && b < n && !g[a][b] && !st[a][b])
                {
                    q.push({a, b});
                    st[a][b] = 1;
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();

        vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '/')
                {
                    int x = i * 3, y = j * 3;
                    g[x + 2][y] = g[x + 1][y + 1] = g[x][y + 2] = 1;
                }
                else if(grid[i][j] == '\\')
                {
                    int x = i * 3, y = j * 3;
                    g[x + 2][y + 2] = g[x + 1][y + 1] = g[x][y] = 1;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < g.size(); i++)
        {
            for(int j = 0; j < g[0].size(); j++)
            {
                if(!g[i][j] && !st[i][j])
                {
                    bfs(g, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

