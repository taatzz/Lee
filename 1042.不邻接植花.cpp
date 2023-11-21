/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 20010;
    int h[N], e[N * 2], ne[N * 2], idx = 0;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
    }

    // 因为每个花坛最大只有三条路径，所以一定存在一个方案，对于每一个花坛将周围已经种过花坛的花进行删除，然后找到没有种过的花
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        memset(h, -1, sizeof h);
        for(auto e : paths)
        {
            int a = e[0] - 1, b = e[1] - 1;
            add(a, b), add(b, a);
        }

        vector<int> res(n, 0);
        for(int i = 0; i < n; i++)
        {
            int mask = 1;
            // 将每个花坛周围已经标记的花删除
            for(int j = h[i]; j != -1; j = ne[j])
            {
                int k = e[j];
               mask |= 1 << res[k];
            }
            // 统计尾0的个数
            res[i] = __builtin_ctz(~mask);
        }
        return res;
    }
};
// @lc code=end

