/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 *
 * [1702] 修改后的最大二进制字符串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.size();

        bool flag = false;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0') flag = true;
            else if(flag && s[i] == '1') cnt++; 
        }

        string res(n, '1');

        if(!flag) return s;
        else 
        {
            res[n - cnt - 1] = '0';
            return res;
        }
    }
};
// @lc code=end

