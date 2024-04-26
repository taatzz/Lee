/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 110;
    int s[N][N];

    int numSubmatrixSumTarget(vector<vector<int>>& g, int target) {
        int m = g.size(), n = g[0].size();
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i - 1][j - 1];
            }
        }

        int res = 0;
        for(int top = 1; top <= m; top++)
        {
            for(int bot = top; bot <= m; bot++)
            {
                unordered_map<int, int> h;
                for(int r = 1; r <= n; r++)
                {
                    int cur = s[bot][r] - s[top - 1][r];
                    if(cur == target) res++;
                    if(h.count(cur - target)) res += h[cur - target];
                    h[cur]++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

