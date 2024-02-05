/*
 * @lc app=leetcode.cn id=1559 lang=cpp
 *
 * [1559] 二维网格图中探测环
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 510;
    int g[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    int a = i + dx[k], b = j + dy[k];
                    if(a >= 0 && a < m  && b >= 0 && b < n && grid[i][j] == grid[a][b])
                    {
                        g[i][j]++;
                    }
                }
            }
        }

        // 无向图拓扑排序
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                if(g[i][j] <= 1) q.push({i, j});
        }

        int cnt = 0;
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            cnt++;

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == grid[t.first][t.second])
                {
                    if(--g[a][b] == 1)
                        q.push({a, b});
                }
            }
        }

        return cnt != n * m;
    }
};
// @lc code=end

