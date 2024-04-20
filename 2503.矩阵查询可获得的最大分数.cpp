/*
 * @lc app=leetcode.cn id=2503 lang=cpp
 *
 * [2503] 矩阵查询可获得的最大分数
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> res;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    void bfs(vector<vector<int>>& g)
    {
        int m = g.size(), n = g[0].size();
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> qe;
        qe.push({g[0][0], {0, 0}});
        vector<vector<bool>> st(m + 1, vector<bool>(n + 1, 0));
        st[0][0] = 1;
        int sum = 0;

        while(q.size())
        {
            auto x = q.top();
            q.pop();

            while(qe.size() && qe.top().first < x.first)
            {
                sum++;
                auto t = qe.top();
                qe.pop();
                int xx = t.second.first, yy = t.second.second;
                for(int i = 0; i < 4; i++)
                {
                    int a = xx + dx[i], b = yy + dy[i];
                    if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b])
                    {
                        st[a][b] = 1;
                        qe.push({g[a][b], {a, b}});
                    }
                }
            }
            res[x.second] = sum;
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        res.resize(queries.size());
        for(int i = 0; i < queries.size(); i++)
        {
            q.push({queries[i], i});
        }

        bfs(grid);

        return res;
    }
};
// @lc code=end

