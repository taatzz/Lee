/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 *
 * [1793] 好子数组的最大分数
 */

// @lc code=start
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        vector<int> left(n, -1), right(n, n);

        for(int i = 0; i < n; i++)
        {
            while(st.size() && nums[st.top()] >= nums[i])
            {
                right[st.top()] = i;
                st.pop();
            }

            if(st.size()) left[i] = st.top();
            st.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(left[i] + 1 <= k && right[i] - 1 >= k)
            {
                int len = right[i] - left[i] - 1;
                res = max(res, nums[i] * len);
            }
        }

        return res;
    }
};
// @lc code=end

