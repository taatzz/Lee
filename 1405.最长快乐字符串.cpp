/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, char> PIC;

    string longestDiverseString(int a, int b, int c) {
        priority_queue<PIC> q;
        if(a > 0)
            q.push({a, 'a'});
        if(b > 0)
            q.push({b, 'b'});
        if(c > 0)
            q.push({c, 'c'});

        string res;
        while(true)
        {
            if(q.size() == 0) break;
            auto t = q.top();
            q.pop();
            if(res.size() >= 2)
            {
                int n = res.size();
                if(res[n - 1] == t.second && res[n - 2] == t.second)
                {
                    if(q.size() == 0) break;
                    auto tmp = q.top();
                    q.pop();
                    res += tmp.second;
                    tmp.first--;
                    if(tmp.first > 0) q.push(tmp);
                    q.push(t);
                }
                else
                {
                    res += t.second;
                    t.first--;
                    if(t.first > 0)
                        q.push(t);
                }
            }
            else
            {
                res += t.second;
                t.first--;
                if(t.first > 0)
                    q.push(t);
            }
        }

        return res;
    }
};
// @lc code=end

