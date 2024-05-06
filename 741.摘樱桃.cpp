/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 55;
    int mem[N][N][N][N];
    int dx[2] = { 1,0 };
    int dy[2] = { 0,1 };
    int dfs(vector<vector<int>>& g, int x1, int y1, int x2, int y2)
    {
        int n = g.size();

        if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return -1;
        if(x1 >= n || y1 >= n || x2 >= n || y2 >= n) return -1;
        if(g[x1][y1] == -1 || g[x2][y2] == -1) return -1;

        if(x1 == n - 1 && y1 == n - 1) return g[x1][y1];
        if(mem[x1][y1][x2][y2] != -0x3f3f3f3f) return mem[x1][y1][x2][y2];

        int& res = mem[x1][y1][x2][y2];
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                res = max(res, dfs(g, x1 + dx[i], y1 + dy[i], x2 + dx[j], y2 + dy[j]));
            }
        }

        if(res < 0) return -1;
        res += g[x1][y1];
        if(x1 != x2 && y1 != y2) res += g[x2][y2];

        return res;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                for(int k = 0; k < N; k++)
                    for(int m = 0; m < N; m++)
                        mem[i][j][k][m] = -0x3f3f3f3f;
        }
        return max(0, dfs(grid, 0, 0, 0, 0));
    }
};
// @lc code=end

