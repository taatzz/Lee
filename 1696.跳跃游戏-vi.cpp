/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n, 0);

        f[0]= nums[0];
        // 单调队列保存前面的最大值
        deque<int> q;
        q.push_back(0);
        for(int i = 1; i < n; i++)
        {
            while(q.size() && i - q.front() > k) q.pop_front();

            f[i] = nums[i] + f[q.front()];

            while(q.size() && f[i] >= f[q.back()]) q.pop_back();
            q.push_back(i);
        }

        return f[n - 1];
    }
};
// @lc code=end

