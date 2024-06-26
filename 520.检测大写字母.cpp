/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string s) {
        int cnt = 0;
        for(auto e : s)
        {
            if(isupper(e)) cnt++;
        }

        if(cnt == 0) return 1;
        else if(cnt == 1 && isupper(s[0])) return 1;
        else if(cnt == s.size()) return 1;
        else return 0;
    }
};
// @lc code=end

