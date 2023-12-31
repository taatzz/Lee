/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边界着色
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 50;
    bool st[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void dfs(vector<vector<int>>& g, int x, int y, int c, vector<vector<int>>& tmp)
    {
        int t = g[x][y];
        st[x][y] = true;
        int m = g.size(), n = g[0].size();
        if(x == 0 || y == 0 || x == m - 1 || y == n - 1)
            g[x][y] = c;

        bool flag = false;

        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            
            if(a >= 0 && a < m && b >= 0 && b < n && tmp[a][b] != t)
                    flag = true;
            if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b] && g[a][b] == t)
                dfs(g, a, b, c, tmp);
        }
        if(flag) g[x][y] = c;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> tmp(grid);
        dfs(grid, row, col, color, tmp);

        return grid;
    }
};
// @lc code=end

