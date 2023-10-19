// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> Spilt(string s)
    {
        int n = s.size();
        vector<string> tmp;
        string cur;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '/') // 会在数组中插入空字符的
            {
                tmp.push_back(cur);
                cur.clear();
            }
            else
                cur += s[i];
        }

        tmp.push_back(cur);

        return tmp;
    }

    string simplifyPath(string path) {
        vector<string> Path = Spilt(path);

        // 数组模仿栈方便顺序输出
        vector<string> stk;

        for(int i = 0; i < Path.size(); i++)
        {
            if(Path[i] == "" || Path[i] == ".") // 空字符和.不做操作
                continue;
            if(Path[i] == "..") // 返回上级目录，不入栈
            {
                if(!stk.empty())
                    stk.pop_back();
                continue;
            }
            stk.push_back(Path[i]);
        }

        string res;
        if(stk.empty()) // 栈空输出根目录
            return "/";
        else
        {
            // 顺序输出路径
            for(auto e : stk)
            {
                res += "/" + e;
            }
        }                 

        return res;                  
    }
};
// @lc code=end

