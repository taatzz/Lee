/*
 * @lc app=leetcode.cn id=2849 lang=cpp
 *
 * [2849] 判断能否在给定时间到达单元格
 */

// @lc code=start
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) return t != 1;
        
        // 斜着走可以最快的到达
        int min_t = max(abs(sx - fx), abs(sy - fy));
        // cout << min_t;

        return t >= min_t;
    }
};
// @lc code=end

