/*
 * @lc app=leetcode.cn id=2522 lang=cpp
 *
 * [2522] 将字符串分割成值不超过 K 的子字符串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    // 贪心的选择每一个字符串的最大长度
    int minimumPartition(string s, int k) {
        int n = s.size();

        int res = 0;
        long long x = 0;
        for(int i = 0; i < n; i++)
        {
            int t = s[i] - '0';
            if(t > k) return -1;

            x = (long)x * 10 + t;
            if(x > k)
            {
                res++;
                x = t;
            }
        }

        // 最后一个字符串是没有计算的需要加上
        return res + 1;
    }
};
// @lc code=end

