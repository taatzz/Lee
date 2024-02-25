/*
 * @lc app=leetcode.cn id=2830 lang=cpp
 *
 * [2830] 销售利润最大化
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    int maximizeTheProfit(int n, vector<vector<int>>& nums) {
        unordered_map<int, vector<PII>> h;

        for(auto& e : nums)
        {
            int a = e[0], b = e[1], c = e[2];
            h[b].push_back({a, c});
        }

        // 销售编号不超过i的房屋的最大利润
        // 第i个房子不卖时：f[i + 1] = f[i];
        // 第i个房子卖时：f[i + 1] = max(f[i + 1], f[start] + w); start为区间起始点
        vector<int> f(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            f[i + 1] = f[i];
            if(h.find(i) != h.end())
                for(auto& e : h[i])
                {
                    f[i + 1] = max(f[i + 1], f[e.first] + e.second);
                }
        }

        return f[n];
    }
};
// @lc code=end

