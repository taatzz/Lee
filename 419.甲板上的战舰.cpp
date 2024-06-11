/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> st(m, vector<bool>(n, 0));

        function<void(int, int)> dfs = [&](int x, int y)
        {
            st[x][y] = 1;

            if(x + 1 < m && grid[x + 1][y] == 'X') dfs(x + 1, y);
            if(y + 1 < n && grid[x][y + 1] == 'X') dfs(x, y + 1);
        };

        int res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 'X' && !st[i][j]) dfs(i, j), res++;

        return res;
    }
};
// @lc code=end

