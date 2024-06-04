#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 2010;
    int h[N], e[N], ne[N], w[N], idx, k;
    bool st[N];

    void add(int a, int b, int c)
    {
        e[idx] = b,  w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    int dfs(int u, int sum)
    {
        st[u] = 1;

        int cnt = sum % k == 0 ? 1 : 0;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(st[j]) continue;
            cnt += dfs(j, sum + w[i]);
        }

        return cnt;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        k = signalSpeed;
        int n = 0;
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c);
            add(b, a, c);
            n = max(n, max(a, b));
        }

        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++)
        {
            int cnt = 0;
            memset(st, 0, sizeof st);
            st[i] = 1;
            for(int j = h[i]; j != -1; j = ne[j])
            {
                int t = dfs(e[j], w[j]);
                
                res[i] += t * cnt;
                cnt += t;
            }
        }

        return res;
    }
};