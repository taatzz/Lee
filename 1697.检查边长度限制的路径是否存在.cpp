/*
 * @lc app=leetcode.cn id=1697 lang=cpp
 *
 * [1697] 检查边长度限制的路径是否存在
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> pii;
    static const int N = 100010;
    int p[N];
    struct node
    {
        int a, b, c, i;
        node(int a, int b, int c, int i) : a(a), b(b), c(c), i(i){}
        bool operator<(node& y)
        {
            return c <= y.c;
        }
    };

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& queries) {
        for(int i = 0; i <= n; i++) p[i] = i;
        vector<pii> edges;
        vector<node> q;
        for(int i = 0; i < queries.size(); i++)
        {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2];
            q.emplace_back(a, b, c, i);
        }
        for(auto& e : edge)
        {
            int a = e[0], b = e[1], c = e[2];
            edges.push_back({c, {a, b}});
        }
        sort(q.begin(), q.end());
        sort(edges.begin(), edges.end());

        vector<bool> res(q.size());
        int j = 0;
        for(int i = 0; i < q.size(); i++)
        {
            int x = q[i].c;
            while(j < edges.size() && x > edges[j].first)
            {
                int a = edges[j].second.first, b = edges[j].second.second;
                a = find(a), b = find(b);
                if(a != b)
                {
                    p[a] = b;
                }
                j++;
            }
            int a = find(q[i].a), b = find(q[i].b);
            if(a == b) res[q[i].i] = 1;
            else res[q[i].i] = 0;
        }

        return res;
    }
};
// @lc code=end

