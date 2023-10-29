/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<char> hash{ 'a','e','i','o','u','A','E','I','O','U' };

        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j)
        {
            while(i < j && hash.find(s[i]) == hash.end())
                i++;
            while(i < j && hash.find(s[j]) == hash.end())
                j--;
            if(i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};
// @lc code=end

