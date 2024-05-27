/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string t;

        function<void(int)> dfs = [&](int x)
        {
            int n = s.size();
            if(x >= n)
            {
                res.push_back(t);
                return;
            }

            char c = s[x];
            if(isalpha(c))
            {
                c = tolower(c);
                t += c;
                dfs(x + 1);
                t.pop_back();

                t += toupper(c);
                dfs(x + 1);
                t.pop_back();
            }   
            else 
            {
                t += c;
                dfs(x + 1);
                t.pop_back();
            }
        };

        dfs(0);

        return res;
    }
};
// @lc code=end

