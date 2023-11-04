/*
 * @lc app=leetcode.cn id=1267 lang=cpp
 *
 * [1267] 统计参与通信的服务器
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int> >& g, int x, int y)   
    {
        int n = g.size(), m = g[0].size();
        // 下
        for(int i = x + 1; i < n; i++)
        {
            if(g[i][y])
                return true;
        }
        // 右
        for(int j = y + 1; j < m; j++)
            if(g[x][j]) return true;
        // 左
        for(int j = y - 1; j >= 0; j--)
            if(g[x][j]) return true;
        // 上
        for(int i = x - 1; i >= 0; i--)
            if(g[i][y]) return true;

        return false;
    }

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    if(check(grid, i, j))
                        res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

