/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
//水平或者竖直的四个方向上
// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int res = 0;
    typedef pair<int, int> PII;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void bfs(vector<vector<int> >& g, vector<vector<int> >& st, int x, int y)
    {
        queue<PII> q;
        q.push(pair<int, int>(x ,y));
        st[x][y] = 1;
        int cnt = 1;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a < 0 || a >= g.size() || b < 0 || b >= g[0].size())
                    continue;
                if(!g[a][b])
                    continue;
                if(st[a][b])
                    continue;
                cnt++;
                st[a][b] = 1;
                q.push(pair<int, int>(a, b));
            }
        }
        res = max(res, cnt);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > st(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] && !st[i][j])
                    bfs(grid, st, i, j);
            }
        }

        return res;
    }
};
// @lc code=end

