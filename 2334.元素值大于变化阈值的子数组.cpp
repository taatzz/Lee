/*
 * @lc app=leetcode.cn id=2334 lang=cpp
 *
 * [2334] 元素值大于变化阈值的子数组
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n, - 1), right(n, n);
        stack<int> s;

        for(int i = 0; i < n; i++)
        {
            while(s.size() && nums[s.top()] >= nums[i])
            {
                right[s.top()] = i;
                s.pop();
            }
            if(s.size()) left[i] = s.top();
            s.push(i);
        }
    
        for(int i = 0; i < n; i++)
        {
            int len = right[i] - left[i];
            if(nums[i] > threshold / len) return len;
        }

        return -1;
    }
};
// @lc code=end

