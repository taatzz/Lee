/*
 * @lc app=leetcode.cn id=2834 lang=cpp
 *
 * [2834] 找出美丽数组的最小和
 */

// @lc code=start
#include <iostream>

using namespace std;

// class Solution {
// public:
//     int minimumPossibleSum(int n, int target) {
//         int mod = 1e9 + 7;
//         long long sum = (long long)(1 + n) * n / 2 % mod;

//         int m = 0;
//         if(n < target) m = target;
//         else if(n > target) m = n + 1;
//         else m = n + 1;

//         int t = 1;
//         while(t + t < target)
//         {
//             int dif = target - t;
//             if(dif <= n)
//             {
//                 sum -= dif;
//                 sum += (m++);
//                 sum %= mod;
//             }
//             t++;
//         }

//         return sum;
//     }
// };

class Solution {
public:
    // O(1)求和
    int minimumPossibleSum(int n, int target) {
        long long m = min(n, target / 2); // 前 m 个数(1, target - 1)内每一对只能选择一个
        // 剩余的n - m个数 从k - k + n - m - 1
        int mod = 1e9 + 7;

        return ((m * (m + 1) + ((long long)2 * target + n - m - 1) * (n - m))) / 2 % mod;
    }
};

// @lc code=end

