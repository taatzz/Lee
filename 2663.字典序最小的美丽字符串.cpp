/*
 * @lc app=leetcode.cn id=2663 lang=cpp
 *
 * [2663] 字典序最小的美丽字符串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    // 不能有长度为2或者长度更长的回文串，那么当前字符串如果要替换则不能和前一个字符相同
    //  保证不是长度更长的回文串,那么当前字符替换的应该不和i-2的字符相同
    string smallestBeautifulString(string s, int k) {
        int n = s.size(), start = -1;

        // 第一个可以进行替换的位置
        for(int i = n - 1; i >= 0; i--)
        {
            int u = s[i] - 'a';
            for(int j = 0; j < k; j++)
            {
                char c = 'a' + j;
                // 替换比当前字符大的字符
                if(j <= u) continue;
                if(i - 1 >= 0 && s[i - 1] == c) continue;
                if(i - 2 >= 0 && s[i - 2] == c) continue;
                s[i] = c;
                start = i;
                break;
            }
            if(start != -1) break;
        }
        if(start == -1) return ""; // 无解

        // 可以替换则后面的字符应该替换为最小的可以替换的字符
        for(start++; start < n; start++)
        {
            for(int i = 0; i < k; i++)
            {
                char c = 'a' + i;
                if(start - 1 >= 0 && s[start - 1] == c)continue;
                if(start - 2 >= 0 && s[start - 2] == c) continue;
                s[start] = c;
                break;
            }
        }

        return s;
    }
};
// @lc code=end

