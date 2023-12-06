/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 510;
    bool st[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    bool bfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int x, int y)
    {
        int m = g1.size(), n = g1[0].size();
        queue<PII> q;
        bool flag = 1;
        q.push({x, y});
        st[x][y] = 1;
        if(g1[x][y] != 1) flag = 0;

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < m && b >= 0 && b < n && g2[a][b] && !st[a][b])
                {
                    if(g1[a][b] != 1) flag = 0;
                    st[a][b] = 1;
                    q.push({a, b});
                }
            }
        }

        return flag;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();

        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid2[i][j] && !st[i][j])
                {
                    if(bfs(grid1, grid2, i, j)) res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

