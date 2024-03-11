/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 *
 * [2129] 将标题首字母大写
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string s) {
        int n = s.size();

        string res;
        int i = 0;
        while(i < n)
        {
            int start = i;
            while(i < n && s[i] != ' ') i++;
            if(i - start <= 2)
            {
                while(start < i) res += tolower(s[start++]);
            }
            else
            {
                res += toupper(s[start]);
                start++;
                while(start < i) res += tolower(s[start ++]);
            }
            res += ' ';
            i++;
        }
        res.pop_back();

        return res;
    }
};
// @lc code=end

