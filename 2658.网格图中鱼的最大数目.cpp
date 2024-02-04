/*
 * @lc app=leetcode.cn id=2658 lang=cpp
 *
 * [2658] 网格图中鱼的最大数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 15;
    int res;
    bool st[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int dfs(vector<vector<int>>& g, int x, int y)
    {
        int m = g.size(), n = g[0].size();
        st[x][y] = 1;
        int cnt = g[x][y];
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < m && b >= 0 && b < n && g[a][b] && !st[a][b])
            {
                cnt += dfs(g, a, b);
                st[a][b] = 1;
            }
        }

        return cnt;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] && !st[i][j])
                {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }

        return res;
    }
};
// @lc code=end

