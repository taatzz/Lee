/*
 * @lc app=leetcode.cn id=1293 lang=cpp
 *
 * [1293] 网格中的最短路径
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 50;
    bool st[N][N][N * N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int sum = 0;

    int bfs(vector<vector<int>>& g)
    {
        int m = g.size(), n = g[0].size();
        queue<pair<int, PII>> q;
        q.push({sum, {0, 0}});
        st[0][0][sum] = true;
        int res = 1;

        for(; q.size() > 0; res++)
        {
            int size = q.size();
            while(size--)
            {
                auto t = q.front();
                q.pop();
                int k = t.first, x = t.second.first, y = t.second.second;

                for(int i = 0; i < 4; i++)
                {
                    int a = x + dx[i], b = y + dy[i];
                    if(a >= 0 && a < m && b >= 0 && b < n)
                    {
                        if(g[a][b] == 0 && !st[a][b][k])
                        {
                            if(a == m - 1 && b == n - 1) return res;
                            q.push({k, {a, b}});
                            st[a][b][k] = 1;
                        }
                        else if(g[a][b] == 1 && k > 0 && !st[a][b][k - 1])
                        {
                            q.push({k - 1, {a, b}});
                            st[a][b][k - 1] = 1;
                        }
                    }
                }
            }
        }

        return -1;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if(k >= m + n - 3) return m + n - 2;
        sum = k;

        return bfs(grid);
    }
};
// @lc code=end

