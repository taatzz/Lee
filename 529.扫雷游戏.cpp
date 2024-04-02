/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    static const int N = 55;
    bool st[N][N];
    int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
    int dy[8] = { 1,0,-1,0,1,-1,1,-1 };

    void bfs(vector<vector<char>>& g, int x, int y)
    {
        queue<pii> q;
        q.push({x, y});
        st[x][y] = 1;
        int m = g.size(), n = g[0].size();

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            int cnt = 0;
            for(int i = 0; i < 8; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < m && b >= 0 && b < n)
                {
                    if(g[a][b] == 'M') cnt++;
                }
            }
            if(cnt == 0)
            {
                g[t.first][t.second] = 'B';
                for(int i = 0; i < 8; i++)
                {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b])
                    {
                        st[a][b] = 1;
                        q.push({a, b});
                    }
                }
            }
            else g[t.first][t.second] = '0' + cnt;
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& grid, vector<int>& click) {
        int a = click[0], b = click[1];
        if(grid[a][b] == 'M')
        {
            grid[a][b] = 'X';
            return grid;
        }
        bfs(grid, a, b);

        return grid;
    }
};
// @lc code=end

