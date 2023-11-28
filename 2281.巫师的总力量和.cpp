/*
 * @lc app=leetcode.cn id=2281 lang=cpp
 *
 * [2281] 巫师的总力量和
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int ss[N];
    long long s[N];

    int totalStrength(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;

        vector<int> left(n + 1, -1);
        vector<int> right(n + 1, n);

        stack<int> st;
        for(int i = 0; i < nums.size(); i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);
            s[i + 1] = s[i] + nums[i];
        }

        for(int i = 1; i <= n; i++)
        {
            ss[i + 1] = (ss[i] + s[i]) % mod;
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int l = left[i] + 1, r = right[i] - 1;
            long total = ((long)(i - l + 1) * (ss[r + 2]- ss[i + 1]) - (long)(r - i + 1) * (ss[i + 1] - ss[l])) % mod;
            res = (res + (long long)nums[i] * total) % mod;
        }

        return (res + mod) % mod;
    }
};
// @lc code=end

