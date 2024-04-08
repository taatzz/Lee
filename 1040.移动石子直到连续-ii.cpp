/*
 * @lc app=leetcode.cn id=1040 lang=cpp
 *
 * [1040] 移动石子直到连续 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &s) {
        sort(s.begin(), s.end());
        int n = s.size();
        int e1 = s[n - 2] - s[0] - n + 2;
        int e2 = s[n - 1] - s[1] - n + 2; // 计算空位
        int max_move = max(e1, e2);
        if (e1 == 0 || e2 == 0) // 特殊情况：没有空位
            return {min(2, max_move), max_move};
        int max_cnt = 0, left = 0;
        for (int right = 0; right < n; ++right) { // 滑动窗口：枚举右端点所在石子
            while (s[right] - s[left] + 1 > n) // 窗口长度大于 n
                ++left; // 缩小窗口长度
            max_cnt = max(max_cnt, right - left + 1); // 维护窗口内的最大石子数
        }
        return {n - max_cnt, max_move};
    }
};

// @lc code=end

