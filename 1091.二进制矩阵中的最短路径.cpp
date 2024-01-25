/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 110;
    int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
    int dy[8] = { 1,0,-1,0,1,-1,-1,1 };
    int dist[N][N];
    bool st[N][N];

    void bfs(vector<vector<int>>& g)
    {
        int n = g.size(), m = g[0].size();
        queue<PII> q;
        q.push({0, 0});
        dist[0][0] = 1;
        st[0][0] = true;

        while(q.size())
        {
            auto t = q.front();
            q.pop();
            
            for(int i = 0; i < 8; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 0 && !st[a][b])
                {
                    dist[a][b] = dist[t.first][t.second] + 1;
                    st[a][b] = true;
                    q.push({a, b});
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 1) return -1;
        bfs(grid);

        return dist[n - 1][m - 1] == 0 ? -1 : dist[n - 1][m - 1];
    }
};
// @lc code=end

