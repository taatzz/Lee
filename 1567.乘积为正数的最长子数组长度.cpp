/*
 * @lc app=leetcode.cn id=1567 lang=cpp
 *
 * [1567] 乘积为正数的最长子数组长度
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        // f[i][0] 表示当前以第i个结尾的结果为负数的最长长度
        // f[i][1] 表示当前以第i个结尾的结果为正数的最长长度
        vector<vector<int>> f(n + 1, vector<int>(2));

        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            if(nums[i - 1] == 0)
            {
                f[i][0] = f[i][1] = 0;
            }
            else if(nums[i - 1] > 0)
            {
                f[i][0] = (f[i - 1][0] == 0 ? 0 : f[i - 1][0] + 1);
                f[i][1] = f[i - 1][1] + 1;
            }
            else
            {
                f[i][0] = f[i - 1][1] + 1;
                f[i][1] = (f[i - 1][0] == 0 ? 0 : f[i - 1][0] + 1);
            }
            res = max(res, f[i][1]);
        }

        return res;
    }
};
// @lc code=end

