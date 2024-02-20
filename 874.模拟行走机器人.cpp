/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int dx[5] = { 0,1,0,-1,0 };

    int f(int x, int y)
    {
        return x * 60010 + y;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> h;
        for(auto& e : obstacles)
        {
            int a = e[0], b = e[1];
            h.insert(f(a, b));
        }

        int res = 0, k = 0;
        int x = 0, y = 0;
        for(auto c : commands)
        {
            if(c == -2)
                k = (k + 3) % 4;
            else if(c == -1)
                k = (k + 1) % 4;
            else
            {
                while(c --)
                {
                    int a = x + dx[k], b = y + dx[k + 1];
                    if(h.count(f(a, b)))
                        break;
                    x = a;
                    y = b;
                    res = max(res, x * x + y * y);
                }
            }
        }

        return res;
    }
};
// @lc code=end

