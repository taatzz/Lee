/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 110;
    int dist[N][N];
    bool st[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int maxDistance(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        queue<PII> q;
        int res = -1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(g[i][j] == 1)
                {
                    st[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b])
                {
                    dist[a][b] = dist[t.first][t.second] + 1;
                    res = max(res, dist[a][b]);
                    st[a][b] = 1;
                    q.push({a, b});
                }
            }
        }

        return res;
    }
};
// @lc code=end

