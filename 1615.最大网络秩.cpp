/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 110;
    int g[N][N];

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> f(n);

        for(auto e : roads)
        {
            int a = e[0], b = e[1];
            g[a][b] = g[b][a] = 1;
            // 统计每个点的边数
            f[a]++;
            f[b]++;
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int tmp = f[i] + f[j] - (g[i][j] == 1 ? 1 : 0);
                res = max(res, tmp);
            }
        }

        return res;
    }
};
// @lc code=end

