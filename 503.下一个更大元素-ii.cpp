/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> res(n, -1);
        for(int i = 0; i < n * 2; i++)
        {
            while(st.size() && nums[st.top() % n] < nums[i % n])
            {
                res[st.top() % n] = nums[i % n];
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

