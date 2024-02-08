/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 410;
    int h[N], e[N], ne[N], w[N], idx;
    int h1[N], e1[N], ne1[N], w1[N], idx1;
    int dist[N];
    bool st[N * 4][2];

    void add(int a, int b, int c)
    {
        if(c == 0)
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        else
            e1[idx1] = b, ne1[idx1] = h1[a], h1[a] = idx1++;
    }

    void bfs()
    {
        memset(dist, -1, sizeof dist);
        queue<pair<int, int>> q;
        q.push({0, 1});
        q.push({0, 0});
        int d = 0;

        while(q.size())
        {
            for(int k = q.size(); k; k--)
            {
                auto [t, c] = q.front();
                q.pop();

                if(dist[t] == -1)
                    dist[t] = d;
                st[t][c] = true;
                if(c == 0)
                {
                    for(int i =  h1[t]; i != -1; i = ne1[i])
                    {
                        int j = e1[i];
                        if(!st[j][c ^ 1])
                            q.push({j, c ^ 1});
                    }
                }
                else
                {
                    for(int i = h[t]; i != -1; i = ne[i])
                    {
                        int j = e[i];
                        if(!st[j][c ^ 1])
                            q.push({j, c ^ 1});
                    }
                }
            }
            
            d++;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        memset(h, -1, sizeof h);
        memset(h1, -1, sizeof h1);

        for(auto& e : red)
        {
            int a = e[0], b = e[1];
            add(a, b, 0);
        }
        for(auto& e : blue)
        {
            int a = e[0], b = e[1];
            add(a, b, 1);
        }

        bfs();

        vector<int> res(n);
        for(int i = 0; i < n; i++)
        {
            res[i] = dist[i];
        }

        return res;
    }
};
// @lc code=end

