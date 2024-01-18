/*
 * @lc app=leetcode.cn id=2730 lang=cpp
 *
 * [2730] 找到最长的半重复子字符串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size(), res = 1, t = 0;

        for(int i = 1, j = 0; i < n; i++)
        {
            // 相邻的字符相同，相同次数 + 1
            if(s[i] == s[i - 1] && ++t > 1)
            {
                j++;
                // 找到左边可以使左边的相邻重复子串
                while(j <= i && s[j] != s[j - 1])
                {
                    j++;
                }
                t = 1;
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};
// @lc code=end

