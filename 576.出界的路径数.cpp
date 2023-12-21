/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 60, mod = 1e9 + 7;
    int _m, _n;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int mem[N][N][N];

    int dfs(int x, int y, int max)
    {
        if(x < 0 || x >= _m || y < 0 || y >= _n)
            return 1;
        if(max == 0)
            return 0;

        if(mem[x][y][max] != -1) return mem[x][y][max];

        int res = 0;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            res += dfs(a, b, max - 1);
            res %= mod;
        }
        mem[x][y][max] = res;
        return res;
    }

    int findPaths(int m, int n, int max, int x, int y) {
        _m = m, _n = n;
        memset(mem, -1, sizeof mem);

        int res = dfs(x, y, max);

        return res;
    }
};
// @lc code=end

