/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大子序列交替和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> f(1, vector<long long>(2));
        f[0][1] = nums[0];
        long long odd = f[0][1], eve = f[0][0];
        long long res = odd;
        for(int i = 1; i < n; i++)
        {
            f[0][0] = odd - nums[i];
            f[0][1] = eve + nums[i];
            odd = max(odd, f[0][1]);
            eve = max(eve, f[0][0]);

            res = max(res, f[0][0]);
            res = max(res, f[0][1]);
        }

        return res;
    }
};
// @lc code=end

