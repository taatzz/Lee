/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 *
 * [2697] 字典序最小回文串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();

        int l = 0, r = n - 1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                if(s[l] < s[r])
                    s[r] = s[l];
                else 
                    s[l] = s[r];
            }
            l++;
            r--;
        }

        return s;
    }
};
// @lc code=end

