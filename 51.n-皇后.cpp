/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    bool check(vector<string>& tmp, int x, int y)
    {
        // 只有上面的格子放了皇后（只需要对比上面的皇后）
        // 上
        for(int i = 0; i < tmp.size(); i++)
            if(tmp[i][y] == 'Q')
                return false;  
        // 左上
        for(int a = x, b = y; a >= 0 && b >= 0; a--, b--)
            if(tmp[a][b] == 'Q')
                return false;
        // 右上
        for(int a = x, b = y; a >= 0 && b < tmp.size(); a--, b++)
            if(tmp[a][b] == 'Q')
                return false;
        return true;
    }

    void dfs(vector<string>& tmp, int x, int n)
    {
        if(x >= n)
        {
            res.push_back(tmp);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(!check(tmp, x, i))
                continue;
            tmp[x][i] = 'Q';
            dfs(tmp, x + 1, n);
            tmp[x][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n, string(n, '.'));
        
        dfs(tmp, 0, n);

        return res;
    }
};
// @lc code=end

