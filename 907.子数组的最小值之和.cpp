/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n + 1, -1);
        vector<int> right(n + 1, n);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[i] <= arr[st.top()]) 
            {
                right[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        // vector<int> right(n + 1, n);
        // while(!st.empty()) st.pop();

        // for(int i = n - 1; i >= 0; i--)
        // {
        //     while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
        //     if(!st.empty()) right[i] = st.top();
        //     st.push(i);
        // }

        int mod = 1e9 + 7;
        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            res += (long long) arr[i] * (i - left[i]) * (right[i] - i);
        }

        return res % mod;
    }
};
// @lc code=end

