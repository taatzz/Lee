/*
 * @lc app=leetcode.cn id=2513 lang=cpp
 *
 * [2513] 最小化两个数组中的最大值
 */

// @lc code=start
#include <unordered_set>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeSet(int k1, int k2, int cnt1, int cnt2) {
        long l = cnt1 + cnt2, r = 2e9;
        long lc = lcm((long)k1, (long(k2)));

        auto check = [&](long x)->bool
        {
            int a = x - x / k1; // 不能整除k1
            int b = x - x / k2; // 不能整除k2
            int com = x - x / k1 - x / k2 + x / lc; // 既不能整除k1也不能整除k2

            return com >= (cnt1 - a) + (cnt2 - b);
        };

        while(l < r)
        {
            long mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

