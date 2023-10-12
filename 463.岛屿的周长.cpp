/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int a = i + dx[k], b = j + dy[k];
                        // 越界也是没有和陆地相连的
                        if(a < 0 || a >= m || b < 0 || b >= n)
                        {
                            res++;
                            continue;
                        }
                        if(grid[a][b] != 1)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

