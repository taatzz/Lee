/*
 * @lc app=leetcode.cn id=2810 lang=cpp
 *
 * [2810] 故障键盘
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string finalString(string s) {
        int n = s.size();

        string res;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'i')
                reverse(res.begin(), res.end());
            else res += s[i];
        }

        return res;
    }
};
// @lc code=end

