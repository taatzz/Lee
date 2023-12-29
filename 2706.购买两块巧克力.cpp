/*
 * @lc app=leetcode.cn id=2706 lang=cpp
 *
 * [2706] 购买两块巧克力
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int sum = prices[0] + prices[1];

        return money >= sum ? money - sum : money;
    }
};
// @lc code=end

