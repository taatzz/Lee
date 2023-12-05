/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 60;
    typedef pair<int, int>  PII;
    queue<PII> q;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    bool st[N][N];

    bool check(vector<vector<int>>& g, int x)
    {
        memset(st, 0, sizeof st);
        if(x >= g[0][0])
            q.push({0,0});
        else return false;
        st[0][0] = 1;

        int n = g.size();
        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];

                if(a < 0 || a >= n || b < 0 || b >= n) continue;
                if(st[a][b]) continue;
                if(g[a][b] > x) continue;

                st[a][b] = 1;
                q.push({a, b});
            }
        }

        return st[n - 1][n - 1];
    }

    int swimInWater(vector<vector<int>>& grid) {
        int l = 0, r = 2500;

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(grid, mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

