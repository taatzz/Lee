/*
 * @lc app=leetcode.cn id=2257 lang=cpp
 *
 * [2257] 统计网格图中没有被保卫的格子数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<vector<int>>& g, int x, int y, vector<vector<bool>>& st)
    {
        int m = g.size(), n = g[0].size();
        int res = 0;
        // 上
        for(int i = x - 1; i >= 0; i--)
        {
            if(g[i][y] == 0 && !st[i][y]) 
            {
                res++;
                st[i][y] = 1;
            }
            else if(g[i][y] == 1 || g[i][y] == 2) break; 
        }
        // 右
        for(int j = y + 1; j < n; j++)
            if(g[x][j] == 0 && !st[x][j])
            {
                res++;
                st[x][j] = 1;
            }
            else if(g[x][j] == 1 || g[x][j] == 2) break;

        // 下
        for(int i = x + 1; i < m; i++)
            if(g[i][y] == 0 && !st[i][y]) 
            {
                res++;
                st[i][y] = 1;
            }
            else if(g[i][y] == 1 || g[i][y] == 2) break;

        // 左
        for(int j = y - 1; j >= 0; j--)
        {
            if(g[x][j] == 0 && !st[x][j]) 
            {
                res++;
                st[x][j] = 1;
            }
            else if(g[x][j] == 1 || g[x][j] == 2) break;
        }

        return res;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> g(m, vector<int>(n, 0));
        vector<vector<bool>> st(m, vector<bool>(n, 0));

        for(auto& e : guards)
        {
            int a = e[0], b = e[1];
            g[a][b] = 1;
        }
        for(auto& e : walls)
        {
            int a = e[0], b = e[1];
            g[a][b] = 2;
        }

        int res = 0;
        for(auto& e : guards)
        {
            int a = e[0], b = e[1];
            res += find(g, a, b, st);
        }

        return m * n - res - guards.size() - walls.size();
    }
};
// @lc code=end

