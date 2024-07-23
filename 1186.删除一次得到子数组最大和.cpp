/*
 * @lc app=leetcode.cn id=1186 lang=cpp
 *
 * [1186] 删除一次得到子数组最大和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(2, INT_MIN / 2));
        int res = INT_MIN;

        for(int i = 1; i <= n; i++)
        {
            f[i][0] = max(f[i - 1][0], 0) + nums[i - 1];
            f[i][1] = max(f[i - 1][0], f[i - 1][1] + nums[i - 1]);
            res = max({res, f[i][0], f[i][1]});
        }

        return res;
    }
};
// @lc code=end

