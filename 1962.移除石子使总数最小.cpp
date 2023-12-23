/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q(piles.begin(), piles.end());

        while(k --)
        {
            int t = q.top();
            q.pop();
            q.push(t - t / 2);
        }

        int res = 0;
        while(q.size())
        {
            int t = q.top();
            q.pop();
            res += t;
        }

        return res;
    }
};
// @lc code=end

