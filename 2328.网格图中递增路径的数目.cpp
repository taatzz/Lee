/*
 * @lc app=leetcode.cn id=2328 lang=cpp
 *
 * [2328] 网格图中递增路径的数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int mem[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    long long ans = 0;
    int mod = 1e9 + 7;

    int dfs(vector<vector<int>>& g, int x, int y)
    {
        int m = g.size(), n = g[0].size();
        int& res = mem[x][y];
        if(res) return res;

        int cnt = 1;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < m && b >= 0 && b < n && g[a][b] > g[x][y])
            {
                cnt += dfs(g, a, b) % mod;
            }
        }

        return res = cnt;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans = (ans + dfs(grid, i, j)) % mod;
            }
        }

        return ans;
    }
};
// @lc code=end

