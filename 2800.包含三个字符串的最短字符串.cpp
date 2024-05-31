/*
 * @lc app=leetcode.cn id=2800 lang=cpp
 *
 * [2800] 包含三个字符串的最短字符串
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string> t = { a, b, c };

        string res;
        auto find = [&]()
        {
            string s = t[0];
            for(int i = 1; i < 3; i++)
            {
                for(int l = 0; l <= s.size(); l++)
                {
                    int len = min((int)s.size() - l, (int)t[i].size());
                    if(s.substr(l, len) == t[i].substr(0, len))
                    {
                        s += t[i].substr(len);
                        break;
                    }
                }
            }

            if(res.size() == 0) res = s;
            else if(res.size() > s.size()) res = s;
            else if(res.size() == s.size() && res > s) res = s;
        };

        for(int i = 0; i < 6; i++)
        {
            find();
            next_permutation(t.begin(), t.end());
        }

        return res;
    }
};
// @lc code=end

