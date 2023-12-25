/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int m, int n) {
        vector<int> res;
        // x + y = n, 4x + 2y = m 满足条件的解（正整数）
        if(m % 2) return res;
        if(m / 2 - n < 0) return res;
        if(2 * n - m / 2 < 0) return res;

        int x = m / 2 - n, y = 2 * n - m / 2;
        res.push_back(x);
        res.push_back(y);

        return res;
    }
};
// @lc code=end

