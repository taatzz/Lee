#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int mx, vector<vector<int>>& roads) {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
        for(auto& e : roads)
        {
            int a = e[0], b = e[1], c = e[2];
            g[a][b] = min(g[a][b], c);
            g[b][a] = min(g[b][a], c);
        }

        vector<vector<int>> f(n);
        auto check = [&](int x)
        {
            for(int i = 0; i < n; i++)
            {
                if((x >> i) & 1) f[i] = g[i];
            }
            for(int k = 0; k < n; k++)
            {
                if((x >> k & 1) == 0) continue;
                for(int i = 0; i < n; i++)
                {
                    if((x >> i & 1) == 0) continue;
                    for(int j = 0; j < n; j++)
                    {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                    }
                }
            }
            for(int i = 0; i < n; i++)
            {
                if((x >> i & 1) == 0) continue;
                for(int j = 0; j < n; j++)
                {
                    if(i == j) continue;
                    if((x >> j) & 1 && f[i][j] > mx) return false;
                }
            }

            return true;
        };

        int res = 0;
        for(int i = 0; i < (1 << n); i++)
        {
            res += check(i);
        }

        return res;
    }
};