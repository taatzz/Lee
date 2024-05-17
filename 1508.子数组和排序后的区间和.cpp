/*
 * @lc app=leetcode.cn id=1508 lang=cpp
 *
 * [1508] 子数组和排序后的区间和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> t;

    int rangeSum(vector<int>& nums, int n, int left, int right) {

        auto find = [&](int k)
        {
            int sum = 0;
            for(int i = 0; i < k - 1; i++) sum += nums[i];

            for(int i = k - 1; i < n; i++)
            {
                int j = i - k + 1;
                sum += nums[i];
                t.push_back(sum);
                sum -= nums[j];
            }
        };

        for(int i = 1; i <= n; i++)
        {
            find(i);
        }
        sort(t.begin(), t.end());

        int res = 0, mod = 1e9 + 7;
        for(int i = left - 1; i < right; i++)
            res = (res + t[i]) % mod;

        return res;
    }
};
// @lc code=end

