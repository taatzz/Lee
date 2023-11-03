/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    void bfs(vector<vector<int>>& g, vector<vector<int>>& s, int x, int y, bool& f)
    {
        queue<pair<int, int> > q;
        q.push({x, y});
        s[x][y] = 1;
        int n = g.size(), m = g[0].size();
        if(x == 0 || y == 0 || x == n - 1 || y == m - 1)
            f = 0;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            if(t.first == 0 || t.second == m - 1 || t.second == 0 || t.first == n - 1)
            f = 0;
            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 0 && s[a][b] == 0)
                {
                    q.push({a, b});
                    s[a][b] = 1;
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        if(grid.size() == 1)
            return 0;
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> >st(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0 && st[i][j] == 0)
                {
                    bool flag = true;
                    bfs(grid, st, i, j, flag);
                    if(flag)
                        res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

