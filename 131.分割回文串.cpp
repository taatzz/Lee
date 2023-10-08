/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> tmp;
    vector<vector<string>> res;

    bool is_pa(string s, int start, int end)
    {
        for(int i = start, j = end; i < j; i++, j--)
        {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }

    void dfs(int start, string s)
    {
        if(start == s.size())
        {
            res.push_back(tmp);

            return;
        }

        for(int i = start; i < s.size(); i++)
        {
            if(is_pa(s, start, i))
            {
                string str = s.substr(start, i - start + 1);
                tmp.push_back(str);
            }
            else
                continue;
            dfs(i + 1, s);
            tmp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);

        return res;
    }
};
// @lc code=end

