/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int i = 0;
        while(i < n && s[i] == ' ') i++;
        bool flag = 1;
        if(s[i] == '-') flag = 0, i++;
        else if(s[i] == '+') i++;

        long long res = 0;
        bool st = 0;
        while(i < n)
        {
            if(!st && s[i] == '0') 
            {
                i++;
                continue;
            }
            st = 1;
            if(s[i] >= '0' && s[i] <= '9') res = res * 10 + (s[i] - '0'), i++;
            else break;

            if(!flag && res - 1 > INT_MAX) return INT_MIN;
            else if(flag && res > INT_MAX) return INT_MAX;
        }
       
       return flag == 0 ? -res : res;
    }
};
// @lc code=end

