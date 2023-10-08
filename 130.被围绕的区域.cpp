/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void dfs(vector<vector<char>>& g, int x, int y)
    {
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] != 'O')
            return;

        g[x][y] = 'A';
        for(int i = 0; i < 4; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            dfs(g, a, b);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }
        for(int i = 1; i < n - 1; i++)
        {
            if(board[0][i])
                dfs(board, 0, i);
            if(board[m - 1][i])
                dfs(board, m - 1, i);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end

