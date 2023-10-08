/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, get = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < get)
            {
                get = prices[i];
            }
            if(prices[i] - get > res)
                res = prices[i] - get;
        }
        return res;
    }
};
// @lc code=end

