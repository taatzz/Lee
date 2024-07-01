/*
 * @lc app=leetcode.cn id=1927 lang=cpp
 *
 * [1927] 求和游戏
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    bool sumGame(string s) {
        int n = s.size();
        int a = 0, b = 0, cnta = 0, cntb = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '?') 
            {
                if(i < n / 2) cnta++;
                else cntb++;
            }
            else 
            if(i < n / 2) a += s[i] - '0';
            else b += s[i] - '0';
        }

        if((cnta + cntb) % 2) return 1;
        return 9 * (cnta - cntb) / 2 + (a - b) != 0;
    }
};
// @lc code=end

