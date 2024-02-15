/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<int> l(n, -1), r(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(st.size() && nums[st.top()] <= nums[i])
            {
                r[st.top()] = i;
                st.pop();
            }
            if(st.size())
                l[i] = st.top();
            st.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= left && nums[i] <= right) res += (i - l[i]) * (r[i] - i);
        }

        return res;
    }
};
// @lc code=end

