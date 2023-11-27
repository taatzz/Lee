/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_l(n + 1, -1);
        vector<int> min_r(n + 1, n);
        vector<int> max_l(n + 1, -1);
        vector<int> max_r(n + 1, n);
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                min_r[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) min_l[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                max_r[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) max_l[i] = st.top();
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            res += (long long)(i - max_l[i]) * (max_r[i] - i) * nums[i];
            res -= (long long)(i - min_l[i]) * (min_r[i] - i) * nums[i];
        }

        return res;
    }
};
// @lc code=end

