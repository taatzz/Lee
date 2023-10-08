/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> g = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqs", "tuv", "wxyz" };
    vector<string> res;
    string tmp;

    void dfs(int x, string digits)
    {
        if(x == digits.size())
        {
            res.push_back(tmp);
            return;
        }

        int num = digits[x] - '0';
        for(int i = 0; i < g[num].size(); i++)
        {
            tmp.push_back(g[num][i]);
            dfs(x + 1, digits);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};0



            
        dfs(0, digits);

        return res;
    }
};
// @lc code=end

