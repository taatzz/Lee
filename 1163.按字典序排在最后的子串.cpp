/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 *
 * [1163] 按字典序排在最后的子串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int cnt[26];

    string lastSubstring(string s) {
        bool flag = false;
        for(int i = 0; i < s.size(); i++) 
        {
            cnt[s[i] - 'a']++;
            if(i > 0 && s[i] != s[i - 1]) flag = true;
        }
        // 如果只有一个字符直接返回
        if(!flag) return s;
        int n = s.size();

        // res 指向当前最大的字典序的起始位置
        int res = 0;
        // 字典序最大一定是从当前字符串最大的字符开始的
        for(int i = 25; i >= 0; i--)
        {
            if(cnt[i])
            {
                char c = 'a' + i;
                for(int j = s.size() - 1; j >= 0; j--)
                {
                    if(!cnt[i]) break;
                    if(s[j] == c && res == 0)
                    {
                        res = j;
                        cnt[i]--;
                    }
                    else if(s[j] == c)
                    {
                        int k = 0, start = j;
                        // 只比较两个子串长度差的部分，如果差的部分全部相等，那么长的子串字典序大
                        for(; k < res - j && s[res + k] == s[start + k]; k++) {}
                        // 当前子串的所有差值都相等或者当前子串的字典序更大的时候更新答案
                        if(k == res - j || s[start + k] > s[res + k]) res = j;
                    }
                }
                break;
            }
        }

        return s.substr(res);
    }
};
// @lc code=end

