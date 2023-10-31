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
        
        // 单调队列中的二元组即为 (f[j], j)
        deque<pair<int, int>> q;
        q.emplace_back(nums[0], 0);
        int ans = nums[0];
        
        for (int i = 1; i < n; ++i) {
            // 队首的 j 不满足限制
            while (i - q.front().second > k) {
                q.pop_front();
            }
            
            ans = q.front().first + nums[i];
            
            // 队尾的 j 不满足单调性
            while (!q.empty() && ans >= q.back().first) {
                q.pop_back();
            }
            
            q.emplace_back(ans, i);
        }
        
        return ans;
    }
};
// @lc code=end

