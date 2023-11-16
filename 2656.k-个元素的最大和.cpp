/*
 * @lc app=leetcode.cn id=2656 lang=cpp
 *
 * [2656] K 个元素的最大和
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        int res = 0;
        while(k --)
        {
            int t = q.top();
            res += t;
            q.pop();
            q.push(t + 1);
        }

        return res;
    }
};
// @lc code=end

