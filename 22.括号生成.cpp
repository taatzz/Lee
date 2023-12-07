/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> res;
    string tmp;
    int _n;

    bool check()
    {
        stack<int> s1;

        for(int i = 0; i < tmp.size(); i++)
        {
            if(tmp[i] == '(') s1.push(i);
            else
            {
                if(s1.empty()) return false;
                else
                {
                    int x = s1.top();
                    s1.pop();
                    if((i - x) % 2 == 0) return false;
                }
            }
        }

        if(s1.empty()) return true;
        return false;
    }

    void dfs(int x)
    {
        if(x >= _n * 2)
        {
            if(check())
                res.push_back(tmp);
            return;
        }

        tmp += '(';
        dfs(x + 1);
        tmp.pop_back();

        tmp += ')';
        dfs(x + 1);
        tmp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        _n = n;

        dfs(0);

        return res;
    }   
};
// @lc code=end

