/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    bool res = true;
    bool isMatch(string s, string p) {
        if(p[0] == '*')
            return true;

        int depth[27];

        for(int i = 0; i < s.size(); i++)
        {
            depth[s[i] - 'a'] = i;
        }
        int i = 0, j = 0;
        while(i < s.size() && j < p.size())
        {
            if(p[j] == '*')
            {
                i = depth[p[j + 1] - 'a'] + 1;
                j += 2;
                continue;
            }
            if(p[j] == '?')
            {
                i++;
                j++;
                continue;
            }
            if(s[i] != p[j])
                return false;
            i++;
            j++;
        }

        if(i < s.size() || j < p.size())
            return false;
        return true;
    }
};
// @lc code=end

