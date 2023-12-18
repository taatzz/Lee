/*
 * @lc app=leetcode.cn id=2577 lang=cpp
 *
 * [2577] 在网格图中访问一个格子的最少时间
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 100010;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    bool check(vector<vector<int> >& g, int x)
    {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> st(m, vector<int>(n, 0));
        if(g[m -1][n - 1] > x) return false;    
        queue<PII> q;

        int time = x;
        st[m - 1][n - 1] = 1;
        q.push({m - 1, n - 1});

        while(q.size())
        {

            time--;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto t = q.front();
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b] && g[a][b] <= time)
                    {
                        if(a == 0 && b == 0) return true;
                        st[a][b] = true;
                        q.push({a, b});
                    }
                }
            }
        }

        return st[0][0];
    }

    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int m = grid.size(), n = grid[0].size();
        // int l = max(grid.back().back(), m + n - 2) - 1, r = 1e5 + m + n; // 开区间
        int l = 0, r = N;

        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(check(grid, mid)) r = mid;
            else l = mid + 1;
        }

        return l + (l + m + n) % 2;
    }
};
// @lc code=end

