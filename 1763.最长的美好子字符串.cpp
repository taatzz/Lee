/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool check(string s)
    {
        unordered_set<char> h;
        for(auto e : s) h.insert(e);

        for(auto e : s)
        {
            char a = tolower(e), b = toupper(e);
            if(!h.count(a) || !h.count(b)) return false;
        }

        return true;
    }

    string longestNiceSubstring(string s) {
        int n = s.size();
        string res = "";

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(j - i + 1 > res.size() && check(s.substr(i, j - i + 1)))
                    res = s.substr(i, j - i + 1);
            }
        }

        return res;
    }
};
// @lc code=end

