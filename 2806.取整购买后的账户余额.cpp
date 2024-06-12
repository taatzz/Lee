/*
 * @lc app=leetcode.cn id=2806 lang=cpp
 *
 * [2806] 取整购买后的账户余额
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    int accountBalanceAfterPurchase(int k) {
        int l = k, r = k;

        while(l % 10 != 0) l--;
        while(r % 10 != 0) r++;

        if(std::abs(l - k) < std::abs(r - k)) return 100 - l;
        else return 100 - r;
    }
};
// @lc code=end

