/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    //对于
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i] 表示当前店铺可以拿到的最多的现金
        if(n == 1)
            return nums[0];
        vector<int> dp_after(n, 0); // 不考虑尾部最后一个的情况（并不代表首位一定会偷）
        // [0,n-1]
        vector<int> dp_before(n, 0); // 不考虑头部第一个的情况
        // [1,n]
        // (不包含头部）初始化，
        // 第一个店铺的最大价值就是nums[0]
        // 第二个店铺的最大价值就是max(nums[0], nums[1]);

        // 递推公式 dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        dp_after[0] = nums[0];
        dp_after[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n - 1; i++)
        {
            dp_after[i] = max(dp_after[i-1], dp_after[i-2] + nums[i]);
        }
        dp_before[1] = nums[1];
        for(int i = 2; i < n; i++)
        {
            dp_before[i] = max(dp_before[i-1], dp_before[i-2] + nums[i]);
        }

        return max(dp_after[n-1], dp_before[n-1]);
    }
};
// @lc code=end

