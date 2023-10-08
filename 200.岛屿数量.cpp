/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 305;
    int st[N][N];
    typedef pair<int, int> PII;
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int res = 0;

    void bfs(vector<vector<char>>& grid, int x, int y, int n, int m)
    {
        queue<PII> q;
        q.push({x, y});

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a < 0 || a > n || b < 0 || b > m)
                    continue;
                if(grid[a][b] == '0')
                    continue;
                if(st[a][b])
                    continue;

                st[a][b] = 1;     
                q.push({a, b});               
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        memset(st, 0, sizeof(st));

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1' && !st[i][j])
                {
                    bfs(grid, i, j, grid.size(), grid[i].size());
                    res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

