/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());

        while(q.size() > 1)
        {
            int max1 = q.top();
            q.pop();
            int max2 = q.top();
            q.pop();
            if(max1 != max2)
            {
                q.push(max1 - max2);
            }
        }

        return q.empty() ? 0 : q.top();
    }
};
// @lc code=end

