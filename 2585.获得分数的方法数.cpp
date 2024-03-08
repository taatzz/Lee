/*
 * @lc app=leetcode.cn id=2585 lang=cpp
 *
 * [2585] 获得分数的方法数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& nums) {
        int n = nums.size(), mod = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(target + 2));
        f[0][0] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                for(int k = 0; k <= nums[i - 1][0] && k * nums[i - 1][1] <= j; k++)
                {
                    f[i][j] += f[i - 1][j - k * nums[i - 1][1]];
                    f[i][j] %= mod;
                }
            }
        }

        return f[n][target];
    }
};
// @lc code=end

