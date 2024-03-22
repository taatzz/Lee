/*
 * @lc app=leetcode.cn id=2617 lang=cpp
 *
 * [2617] 网格图中最少访问的格子数
 */

// @lc code=start
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // 第i行中有哪些列没有被访问，第j列有哪些行没有被访问
        set<int> row[m], col[n];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i + j > 0)
                {
                    row[i].insert(j);
                    col[j].insert(i);
                }
            }
        }

        queue<PII> q;
        q.push({0, 0});
        int res = -1, cnt = 1;

        while(q.size())
        {
            int size = q.size();
            while(size--)
            {
                auto t = q.front();
                q.pop();

                int x = t.first, y = t.second;
                if(x == m - 1 && y == n - 1) 
                {
                    res = cnt;
                    break;
                }
                // 快速找到x行的大于y列的哪些列
                auto it = row[x].upper_bound(y);
                while(it != row[x].end())
                {
                    if(*it > y + grid[x][y]) break;
                    q.push({x, *it});
                    // 将行和列都删除
                    col[*it].erase(x);
                    it = row[x].erase(it);
                }

                it = col[y].upper_bound(x);
                while(it != col[y].end())
                {
                    if(*it > x + grid[x][y]) break;
                    q.push({*it, y});

                    row[*it].erase(y);
                    it = col[y].erase(it);
                }
            }

            cnt++;
        }

        return res;
    }
};
// @lc code=end

