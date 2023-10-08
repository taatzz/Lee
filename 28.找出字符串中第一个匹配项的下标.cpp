/*
   * @lc app=leetcode.cn id=28 lang=cpp
   *
   * [28] 找出字符串中第一个匹配项的下标
   */

// @lc code=start
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int* kmp_next(string n)
    {
        int* next = new int[n.size()];

        int com_len = 0, i = 1;
        next[0] = 0;
        while(i < n.size())
        {
            if(n[i] == n[com_len])
            {
                com_len += 1;
                next[i] = com_len;
                i++;
            }
            else
            {
                if(com_len > 0)
                {
                    com_len = next[com_len - 1];
                }
                else
                {   
                    next[i] = com_len; 
                    i++;
                }
            }
        }

        return next;
    }

    int kmp(string h, string n)
    {
        int i = 0, j = 0;

        int* next = kmp_next(n);

        while(i < h.size())
        {
            if(h[i] == n[j])
            {
                i++;
                j++;
            }
            else if(j > 0)
            {
                j = next[j - 1];
            }
            else
            {
                i++;
            }

            if(j == n.size())
                return i - j;
        }
        delete[] next;
        return -1;
    }

    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};
// @lc code=end

