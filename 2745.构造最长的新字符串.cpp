/*
 * @lc app=leetcode.cn id=2745 lang=cpp
 *
 * [2745] 构造最长的新字符串
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x == y)
        {
            return (x + y) * 2 + z * 2;
        }
        else
        {
            int n = min(x, y);
            return (n + n + 1) * 2 + z * 2;
        }
    }
};
// @lc code=end

