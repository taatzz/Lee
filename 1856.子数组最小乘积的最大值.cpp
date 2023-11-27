/*
 * @lc app=leetcode.cn id=1856 lang=cpp
 *
 * [1856] 子数组最小乘积的最大值
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n + 1, -1);
        vector<int> right(n + 1, n);

        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);

            // 前缀和计算
            s[i + 1] = s[i] + nums[i];
        }


        long long res = 0, mod = 1e9 + 7;
        for(int i = 0; i < n; i++)
        {
            long long tmp = 0;
            // 前缀和查询 left 和 right 都是开区间，前缀和数组从一开始计算
            int l = left[i] + 2;
            int r = right[i];

            tmp += s[r] - s[l - 1];
            tmp *= nums[i];
            res = max(res, tmp);
        }

        return res % mod;
    }
};
// @lc code=end

