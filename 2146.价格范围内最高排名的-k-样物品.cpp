/*
 * @lc app=leetcode.cn id=2146 lang=cpp
 *
 * [2146] 价格范围内最高排名的 K 样物品
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    vector<PII> tmp;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int x, y;

    static bool cmp(pair<PII, PII>& a, pair<PII, PII>& b)
    {
        if(a.first.first != b.first.first)
            return a.first.first > b.first.first;
        else if(a.first.second != b.first.second)
            return a.first.second > b.first.second;
        else if(a.second.first != b.second.first)
            return a.second.first > b.second.first;
        else return a.second.second > b.second.second;
    }

    void bfs(vector<vector<int>>& g, vector<vector<int>>& dist, int low, int high)
    {
        int m = g.size(), n = g[0].size();
        queue<PII> q;
        q.push({x, y});
        dist[x][y] = 0;
        if(g[x][y] != 1 && g[x][y] >= low && g[x][y] <= high) tmp.push_back({x, y});

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];

                if(a >= 0 && a < m && b >= 0 && b < n && dist[a][b] == -1 && g[a][b] != 0)
                {
                    if(g[a][b] != 1 && g[a][b] >= low && g[a][b] <= high)
                    {
                        tmp.push_back({a, b});    
                    }
                    q.push({a, b});
                    dist[a][b] = dist[t.first][t.second] + 1;
                }
            }
        }
    }

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        x = start[0], y = start[1];
        vector<vector<int>> st(m, vector<int>(n, -1));

        bfs(grid, st, pricing[0], pricing[1]);
        priority_queue<pair<PII, PII>, vector<pair<PII, PII>>, decltype(&cmp)> q(cmp);
        for(auto& e : tmp)
        {
            PII a = e, b = {st[e.first][e.second], grid[e.first][e.second]};
            q.push({b, a});
        }
        vector<vector<int>> res;
        while(q.size() && k)
        {
            auto t = q.top();
            q.pop();
            auto a = t.second;
            res.push_back({a.first, a.second});
            k--;
        }

        return res;
    }
};
// @lc code=end

