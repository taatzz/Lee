/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 *
 * [2735] 收集巧克力
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        for(int i = 0; i < n; i++) f[i][0] = nums[i];
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                f[i][j] = min(f[i][j - 1], nums[(i - j + n) % n]);
            }
        }

        long long res = 1e18;
        for(int k = 0; k < n; k++)
        {
            long long tmp = 0;
            for(int i = 0; i < n; i++)
            {
                tmp += f[i][k];
            }
            res = min(res, tmp + 1LL * x * k);
        }

        return res;
    }
};
// @lc code=end

