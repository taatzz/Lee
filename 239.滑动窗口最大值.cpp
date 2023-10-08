/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

class Solution {
public:
    void push(deque<int>& dq, int i, vector<int>& num)
    {
        // 当前元素大于队列中的元素，删除中队列中的元素
        while(!dq.empty() && num[dq.back()] < num[i]) 
            dq.pop_back();
        dq.push_back(i);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i = 0; i < k; i++)
            push(dq, i, nums);
        res.push_back(nums[dq.front()]);

        for(int i = k; i < nums.size(); i++)
        {
            if(i - dq.front() == k) // 当前最大值不符合滑动窗口
                dq.pop_front();
            push(dq, i, nums);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
// @lc code=end
class solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q; // [num, index]
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first}; // 前k个最大的元素
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            // 不用急于删除元素，只有当前最大值不符合当前的滑动窗口时再删除
            while (q.top().second <= i - k) { // <= 因为可能有相等的元素
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
