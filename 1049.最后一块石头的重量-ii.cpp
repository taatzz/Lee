/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    /*
        将石头分成A和B(A>B)两组，min(A-B)， A-B = sum-B-B
        要求A-B的最小值进而求B的最大值，前提：sum - 2 * heap2 >= 0 等价于 heap2 <= sum / 2
        那么也就是求背包容量为sum/2时可以装的最大价值
    */
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for(int i = 0; i < n; i++)
            sum += stones[i];
        int target = sum / 2;

        vector<vector<int> > dp(n, vector<int>(target + 1, 0));
        for(int j = stones[0]; j <= target; j++)
            dp[0][j] = stones[0];

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                if(j < stones[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
            }
        }

        return sum -= dp[n-1][target] * 2;
    }
};
// @lc code=end

