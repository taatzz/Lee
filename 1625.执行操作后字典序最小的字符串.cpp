/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

// @lc code=start
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string res;

    void bfs(string s, int a, int b)
    {
        unordered_set<string> h;
        queue<string> q;
        q.push(s);

        while(q.size())
        {
            string t = q.front();
            q.pop();
            res = min(res, t);

            string tmp = t;
            for(int i = 1; i < t.size(); i += 2)
            {
                int x = t[i] - '0';
                tmp[i] = ((x + a) % 10) + '0';    
            }
            if(!h.count(tmp))
            {
                h.insert(tmp);
                q.push(tmp);
            }

            string x(t.size(), '0');
            for(int i = 0; i < t.size(); i++)
            {
                x[(i + b) % t.size()] = t[i];
            }
            if(!h.count(x))
            {
                q.push(x);
                h.insert(x);
            }
        }
    }

    string findLexSmallestString(string s, int a, int b) {
        res = s;
        bfs(s, a, b);

        return res;
    }
};
// @lc code=end

