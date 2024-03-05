/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static const int N = 250010;
    int p[N], size[N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i <= n * n; i++) p[i] = i, size[i] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int a = i + dx[k], b = j + dy[k];
                        if(a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == 1)
                        {
                            int x = i * n + j, y = a * n + b;
                            x = find(x), y = find(y);
                            if(x == y) continue;
                            p[x] = y;
                            size[y] += size[x];
                        }
                    }
                }
            }
        }

        int res = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    int sum = 1;
                    unordered_set<int> h;
                    for(int k = 0; k < 4; k++)
                    {
                        int a = i + dx[k], b = j + dy[k];
                        if(a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == 1)
                        {
                            int x = a * n + b;
                            x = find(x);
                            if(h.count(x)) continue;
                            h.insert(x);
                            sum += size[x];
                        }
                    }
                    res = max(res, sum);
                }
            }
        }

        return res == -1 ? n * n : res;
    }
};
// @lc code=end

