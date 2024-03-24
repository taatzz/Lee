/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                if(dp[j-coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};


/*
`

*/
// @lc code=end

