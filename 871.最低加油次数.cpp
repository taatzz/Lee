/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int n = stations.size(), idx = 0;

        // 剩余油量、当前位置和加油次数
        int len = startFuel, loc = 0, res = 0;
        while(loc < target)
        {
            if(len == 0)
            {
                if(!q.empty())
                {
                    len += q.top();
                    res++;
                    q.pop();
                }
                else return -1;
            }
            loc += len;
            len = 0;
            while(idx < n && stations[idx][0] <= loc) q.push(stations[idx++][1]);
        }

        return res;
    }
};
// @lc code=end

