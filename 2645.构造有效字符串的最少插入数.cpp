/*
 * @lc app=leetcode.cn id=2645 lang=cpp
 *
 * [2645] 构造有效字符串的最少插入数
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    // 对于相邻的两个字符，如果前面的字符小于后面的字符说明可以放到同一个abc中
    // 求出一共有多少个abc然后减去源字符串的长度

    int addMinimum(string s) {
        int n = s.size();

        int t = 1;
        for(int i = 1; i < n; i++)
        {
            t += s[i - 1] >= s[i];
        }

        return t * 3 - n;
    }
};
// @lc code=end

