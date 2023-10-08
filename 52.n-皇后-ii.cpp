/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int res = 0;

    bool check(vector<vector<int>>& g, int x, int y)
    {
        // 上
        for(int i = x - 1; i >= 0; i--)
        {
            if(g[i][y] == 1)
                return false;
        }
        // 左上
        for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        {
            if(g[i][j] == 1)
                return false;
        }
        // 右上
        for(int i = x - 1, j = y + 1; i >= 0 && j < g.size(); i--, j++)
        {
            if(g[i][j] == 1)
                return false;
        }

        return true;
    }

    void dfs(vector<vector<int>>& g, int x, int n)
    {
        if(x == n)
        {
            res++;
            return;
        }

        for(int i = 0; i < g.size(); i++)
        {
            if(!check(g, x, i))
                continue;
            g[x][i] = 1;
            dfs(g, x + 1, n);
            g[x][i] = 0;
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n, 0));

        dfs(grid, 0, n);

        return res;
    }
};
// @lc code=end

