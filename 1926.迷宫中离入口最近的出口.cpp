/*
 * @lc app=leetcode.cn id=1926 lang=cpp
 *
 * [1926] 迷宫中离入口最近的出口
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 110;
    bool st[N][N];
    int dist[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int bfs(vector<vector<char>>& g, int x, int y)
    {
        int m = g.size(), n = g[0].size();
        queue<PII> q;
        dist[x][y] = 0;
        st[x][y] = true;
        q.push({x, y});
        
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            int x1 = t.first, y1 = t.second;
            if(dist[x1][y1] != 0 && (x1 == 0 || x1 == m - 1 || y1 == 0 || y1 == n - 1))
                return dist[x1][y1];
            
            for(int i = 0; i < 4; i++)
            {
                int a = x1 + dx[i], b = y1 + dy[i];
                if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b] && g[a][b] == '.')
                {
                    st[a][b] = true;
                    dist[a][b] = dist[x1][y1] + 1;
                    q.push({a, b});
                }
            }
        }

        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        return bfs(maze, entrance[0], entrance[1]);
    }
};
// @lc code=end

