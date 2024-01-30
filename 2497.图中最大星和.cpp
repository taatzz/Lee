/*
 * @lc app=leetcode.cn id=2497 lang=cpp
 *
 * [2497] 图中最大星和
 */

// @lc code=start
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N  = 100010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;

    void add(int a, int b, int c)
    {
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    } 

    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        memset(h, -1, sizeof h);

        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b, vals[b]), add(b, a, vals[a]);
        }

        int res = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            priority_queue<int, vector<int>, less<int>> q;
            for(int a = h[i]; a != -1; a = ne[a])
            {
                q.push(w[a]);
            }

            int t = 0, x = k;
            while(q.size() && x)
            {
                x--;
                // 至多选k条边，也可以不选k条边，只选能获得最大价值的
                t = max(t, t + q.top());
                q.pop();
            }

            res = max(res, t + vals[i]);
        }

        return res;
    }
};
// @lc code=end

