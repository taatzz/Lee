/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 从结果出发，将两大洋岸边可以到达的地方全部遍历
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void dfs(vector<vector<int>>& g, vector<vector<int>>& p, int x, int y)
    {
        if(p[x][y])
            return;
        p[x][y] = 1;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= g.size() || b < 0 || b >= g[0].size() || g[a][b] < g[x][y])
                continue;

            dfs(g, p, a, b);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> p_ocean(m, vector<int>(n, 0));
        vector<vector<int>> a_ocean(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            dfs(heights, p_ocean, i, 0);
            dfs(heights, a_ocean, i, n - 1);
        }
        for(int i = 0; i < n; i++)
        {
            dfs(heights, p_ocean, 0, i);
            dfs(heights, a_ocean, m - 1, i);
        }

        vector<int> tmp;
        vector<vector<int>> res;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(p_ocean[i][j] && a_ocean[i][j])
                {
                    tmp.push_back(i);
                    tmp.push_back(j);
                    res.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        return res;
    }
};
// @lc code=end

