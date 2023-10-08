/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    bool st[8][8];

    void find_Q(vector<vector<char>>& g, int x, int y)
    {
        memset(st, 0, sizeof(st));
        for(int i = y; i < 8; i++) // 右
        {
            if(g[x][i] == 'Q' && !st[x][i])
            {
                path.push_back(x);
                path.push_back(i);
                st[x][i] = true;
                res.push_back(path);
                path.clear();
                break;
            }
        }
        for(int i = y; i >= 0; i--) // 左
        {
            if(g[x][i] == 'Q' && !st[x][i])
            {
                path.push_back(x);
                path.push_back(i);
                st[x][i] = true;
                res.push_back(path);
                path.clear();
                break;
            }
        }
        for(int i = x; i >= 0; i--) // 上
        {
            if(g[i][y] == 'Q' && !st[i][y])
            {
                path.push_back(i);
                path.push_back(y);
                st[i][y] = true;
                res.push_back(path);
                path.clear();
                break;
            }
        }
        for(int i = x; i < 8; i++) // 下
        {
            if(g[i][y] == 'Q' && !st[i][y])
            {
                path.push_back(i);
                path.push_back(y);
                st[i][y] = true;
                res.push_back(path);
                path.clear();
                break;
            }
        }
        for(int i = x, j = y; i >= 0 && j >= 0; i--, j--) // 左上
        {
            if(g[i][j] == 'Q' && !st[i][j])
            {
                path.push_back(i);
                path.push_back(j);
                st[i][j] = true;
                res.push_back(path);
                path.clear();
                break;
            }
        }
        for(int i = x, j = y; i < 8 && j >= 0; i++, j--) // 左下
        {
            if(g[i][j] == 'Q' && !st[i][j])
            {
                path.push_back(i);
                path.push_back(j);
                st[i][j] = true;
                res.push_back(path);
                path.clear();
                break;
            }
        }
        for(int i = x, j = y; i >= 0 && j < 8; i--, j++) // 右上
        {
            if(g[i][j] == 'Q' && !st[i][j])
            {
                path.push_back(i);
                st[i][j] = true;
                path.push_back(j);
                res.push_back(path);
                path.clear();
                break;
            }
        }
        for(int i = x, j = y; i < 8 && j < 8; i++, j++) // 右下
        {
            if(g[i][j] == 'Q' && !st[i][j])
            {
                path.push_back(i);
                st[i][j] = true;
                path.push_back(j);
                res.push_back(path);
                path.clear();
                break;
            }
        }
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<char>> g(8, vector<char>(8));

        for(int i = 0; i < queens.size(); i++)
        {
            int x = queens[i][0], y = queens[i][1];
            g[x][y] = 'Q';
        }

        int x = king[0], y = king[1];
        g[x][y] = 'K';

        find_Q(g, x, y);

        return res;
    }
};
// @lc code=end

