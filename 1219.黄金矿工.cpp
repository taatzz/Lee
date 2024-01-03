/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 20;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    bool st[N][N];
    
    int dfs(vector<vector<int>>& g, int x, int y)
    {
        int m = g.size(), n = g[0].size();
        int res = g[x][y];
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < m && b >+ 0 && b < n && g[a][b] && !st[a][b])
            {
                st[a][b] = true;
                res = max(res, g[x][y] + dfs(g, a, b));
                st[a][b] = false;
            }
        }

        return res;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                {
                    st[i][j] = true;
                    dfs(grid, i, j);
                    st[i][j] = false;
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

