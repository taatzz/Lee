/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    bool st[110];
    int res = 0;

    void dfs(vector<int>& num, int x)
    {
        if(x >= num.size())
        {
            int tmp = 0;
            for(int i = 0; i < num.size(); i++)
            {
                if(st[i]) tmp += num[i];
            }
            res = max(tmp, res);
            return;
        }

        st[x] = true;
        dfs(num, x + 2);
        st[x] = false;

        dfs(num, x + 1);
    }

    int rob(vector<int>& nums) {
        // memset(st, 0, sizeof(st));
        // dfs(nums, 0);

        if(nums.size() == 1)
            return nums[0];

        /* 动态规划
            对于当前k(k > 2) 都有偷和不偷
                1.偷：最大总价值为dp[k - 2] + h[k]
                2.不偷：最大总价值为前k-1的个价值总和 dp[k - 1]
            状态转移方程：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            
        */
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};
// @lc code=end

