/*
 * @lc app=leetcode.cn id=2662 lang=cpp
 *
 * [2662] 前往目标的最小代价
 */

// @lc code=start
#include <vector>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 200010;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int h[N], e[N], ne[N], w[N], idx;
    int dist[N];
    bool st[N];
    map<PII, int> hash;

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void insert(int a, int b)
    {
        int size = hash.size();
        if(hash.find({a, b}) == hash.end())
        {
            hash[{a, b}] = size;
        }
    }

    void Dijkstra(int x, int y)
    {
        memset(dist, 0x3f, sizeof dist);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        int s = hash[{x, y}];
        q.push({0, s});
        dist[s] = 0;
        
        while(q.size())
        {
            auto t = q.top();
            q.pop();
            int ver = t.second, d = t.first;
            if(st[ver]) continue;
            st[ver] = 1;

            for(int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(dist[j] > d + w[i])
                {
                    dist[j] = d + w[i];
                    q.push({dist[j], j});
                }
            }
        }
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        memset(h, -1, sizeof h);
        
        insert(start[0], start[1]);
        insert(target[0], target[1]);

        for(auto& e : specialRoads)
        {
            int a = e[0], b = e[1], c = e[2], d = e[3];
            insert(a, b), insert(c, d);
        }

        int n = hash.size();
        int x[n], y[n];
        for(auto& [k, e] : hash)
        {
            x[e] = k.first;
            y[e] = k.second;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                add(i, j, abs(x[i] - x[j]) + abs(y[i] - y[j]));
            }
        }

        for(auto& e : specialRoads)
        {
            int a = hash[{e[0], e[1]}], b = hash[{e[2], e[3]}];
            add(a, b, e[4]);
        }

        Dijkstra(start[0], start[1]);
        int end = hash[{target[0], target[1]}];

        return dist[end];
    }
};
// @lc code=end

