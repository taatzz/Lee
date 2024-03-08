/*
 * @lc app=leetcode.cn id=1802 lang=cpp
 *
 * [1802] 有界数组中指定下标处的最大值
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    bool check(int x, int idx, int n, int m)
    {
        int l = idx + 1, r = n - idx - 1;
        int len1 = x, len2 = x - 1;
        len1 = min(l, len1);
        len2 = min(r, len2);

        long long left = (long long)((x - len1 + 1) + x) * len1 / 2 + (l - len1);
        long long right = (long long)(x - 1 + x - len2) * len2 / 2 + (r - len2);

        return left + right <= m;
    }

    int maxValue(int n, int index, int maxSum) {
        int l = 0, r = maxSum;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(mid, index, n, maxSum)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

