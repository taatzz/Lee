#include <queue>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
    bool st[N];
    int dist[N];

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c);
            add(b, a, c);
        }

        priority_queue<pii, vector<pii>, greater<pii>> q;
        memset(dist, 0x3f, sizeof dist);
        dist[0] = 0;
        q.push({0, 0});
        vector<int> res(n);

        while(q.size())
        {
            auto t = q.top();
            q.pop();
            int d = t.first, ver = t.second;
            if(st[ver]) continue;
            st[ver] = 1;

            for(int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(d + w[i] >= disappear[j]) continue;
                if(d + w[i] < dist[j])
                {
                    dist[j] = d + w[i];
                    q.push({dist[j], j});
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(dist[i] == 0x3f3f3f3f) res[i] = -1;
            else res[i] = dist[i];
        }

        return res;
    }
};