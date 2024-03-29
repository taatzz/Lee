/*
 * @lc app=leetcode.cn id=2812 lang=cpp
 *
 * [2812] 找出最安全路径
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 410;
    bool st[N][N];
    int mem[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    vector<PII> tmp;

    bool check(vector<vector<int>>& g, int x)
    {
        int m = g.size(), n = g[0].size();
        memset(st, 0, sizeof st);
        queue<PII> q;
        int distance = INT_MAX;
        if(mem[0][0]) distance = mem[0][0];
        else
            for(auto e : tmp)
                distance = min(distance, abs(0 - e.first) + abs(0 - e.second));
        if(distance >= x)
        {
            st[0][0] = 1;
            mem[0][0] = distance;
            q.push({0, 0});
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
                    int t = INT_MAX;
                    if(mem[a][b])
                        t = mem[a][b];
                    else
                        for(auto e : tmp)
                            t = min(t, abs(a - e.first) + abs(b - e.second));
                    if(t >= x)
                    {
                        q.push({a, b});
                        mem[a][b] = t;
                        st[a][b] = 1;
                    }
                }
            }
        }

        return st[m - 1][n - 1];
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1) tmp.push_back({i, j});

        int l = 0, r = m + n;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(grid, mid)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

