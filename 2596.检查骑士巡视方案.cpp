/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dx[8] = {2,2,1,-1,-2,-2,-1,1};
    int dy[8] = {-1,1,2,2,1,-1,-2,-2};
    typedef pair<int,int> PII;
    queue<PII> q;

   bool bfs(vector<vector<int>>& g, int x, int y)
    {
          if(g[0][0] != 0)
            return false;
        q.push({ x,y });
        int n = g.size();

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            if(g[t.first][t.second] == n * n - 1)
                return true;
            for(int i = 0; i < 8; i++)        
            {
                auto a = t.first + dx[i];
                auto b = t.second + dy[i];
                if(a >= 0 && a < n && b >= 0 && b < n && g[a][b] == g[t.first][t.second] + 1)              
                {
                    q.push({a,b});
                    break;
                }
            }
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return bfs(grid, 0, 0);
    }
};
// @lc code=end

