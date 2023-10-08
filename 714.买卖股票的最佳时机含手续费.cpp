/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <vector>

using namespace std;

/*
class Solution {
public:
    
    // 首先我们遍历数组的时候，是需要记录下当前时刻之前的最小价格买入股，以保证我手里的股票是以最低价格买入的。
    // 其次，当遇到本次股票可以让我获利时，我就收割本次利润，并且把购买成本换成本次股票价钱。
    // 关键点来了，为什么要有把购买成本换成本次股票价钱这一步操作呢，因为本次利润只是收割，我并没有真正的把我手上的股票的卖出去（如果卖出去，那成本应该重置为0，并且你下一次再想买进的话就需要再付一次手续费了）。
    // 为什么这样做呢，拿prices = [1,3,7,5,10,3], fee = 3 举例。
    // 显而易见我们应该在第一天买入保证我的最低成本为1+3=4，然后我在遍历到7的时候应该卖出去了，因为它可以让我获得7-4=3的利润，但是此时要不要真的卖呢，我不知道。再往后遍历，遇到了10。两种情况
    // 我在7的时候真卖了 那我就需要在5的时候购入成本为5+3=8
    // 我在7的时候假卖，成本为7，(前面说了假卖的时候要把成本换成本次价钱)。也可以理解为假卖就是没卖，成本为1+3=4，利润为10-4=6。 显而易见我假卖的话可以收获更多，这就是贪心
    

    int maxProfit(vector<int>& prices, int fee) {

        int res = 0; 
        int buy = prices[0] + fee;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] + fee < buy)
                buy = prices[i] + fee;
            else if(prices[i] > buy)
            {
                res += prices[i] - buy;
                buy = prices[i];
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // dp[i][j] 表示当前手上的现金
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // 0：当前不持有股票
        // 1：当前持有股票

        dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};
// @lc code=end

