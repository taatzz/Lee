/*
 * @lc app=leetcode.cn id=1958 lang=cpp
 *
 * [1958] 检查操作是否合法
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
    int dy[8] = { 1,0,-1,0,1,-1,1,-1 };

    bool checkMove(vector<vector<char>>& grid, int r, int c, char s) {
        int m = grid.size(), n = grid[0].size();
        grid[r][c] = s;
        auto check = [&](int i)->bool
        {
            int cnt = 1;
            int x = r + dx[i], y = c + dy[i];
            while(x >= 0 && x < m && y >= 0 && y < n)
            {
                if(cnt == 1)
                {
                    if(grid[x][y] == '.' || grid[x][y] == s) return 0;
                }
                else
                {
                    if(grid[x][y] == '.') return 0;
                    if(grid[x][y] == s) return 1;
                }
                cnt++;
                x += dx[i], y += dy[i];
            }

            return 0;
        };

        for(int i = 0; i < 8; i++)
        {
            if(check(i)) return 1;
        }

        return 0;
    }
};
// @lc code=end

