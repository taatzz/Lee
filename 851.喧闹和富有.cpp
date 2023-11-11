/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 510, M = 130010;
    int g[N][N], in[N];

    void topsort(vector<int>& quiet, vector<int>& r)
    {
        queue<int> q;
        int n = quiet.size();
        for(int i = 0; i < n; i++)
        {
            r[i] = i;
            if(!in[i]) 
            {
                q.push(i);
            }
        }

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int u = 0; u < n; u++)
            {
                if(g[t][u] == 1)
                {
                    if(quiet[r[t]] < quiet[r[u]]) r[u] = r[t];
                    if(-- in[u] == 0) q.push(u);
                }
            }
        }
    }
    // 将有钱和没钱建立图，然后在每次拓扑排序时更新安静值6
    // 稠密图采用邻接矩阵
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        for(auto e : richer)
        {
            int a = e[0], b = e[1];
            g[a][b] = 1;
            in[b] ++;
        }
        
        vector<int> res(n);

        topsort(quiet, res);

        return res;
    }
};
// @lc code=end

