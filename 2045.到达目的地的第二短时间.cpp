/*
 * @lc app=leetcode.cn id=2045 lang=cpp
 *
 * [2045] 到达目的地的第二短时间
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 20010;
    int h[N], e[N], ne[N], idx;
    int dist1[N], dist2[N];
    bool st[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = a, h[a] = idx++;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        memset(h, -1, sizeof h);
        for(auto e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }
        queue<PII> q;
        memset(dist1, 0x3f, sizeof dist1);
        memset(dist2, 0x3f, sizeof dist2);
        q.push({0, 1});

        while(q.size())
        {
            auto t = q.front();
            q.pop();
            int dist = t.first, ver = t.second;
            for(int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(dist1[j] > dist + 1)
                {
                    dist2[j] = dist1[j];
                    dist1[j] = dist + 1;
                    q.push({dist1[j], j});
                    q.push({dist2[j], j});
                }
                else if(dist1[j] < dist + 1 && dist2[j] > dist + 1)
                {
                    dist2[j] = dist + 1;
                    q.push({dist2[j], j});
                }
            }
        }

        int res = 0;
        for(int i = 0; i < dist2[n]; i++)
        {
            int a = res / change, b = res % change;
            int wait = a % 2 == 0 ? 0 : change - b;
            res += time + wait;
        }

        return res;
    }
};
// @lc code=end

