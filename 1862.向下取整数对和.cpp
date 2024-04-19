/*
 * @lc app=leetcode.cn id=1862 lang=cpp
 *
 * [1862] 向下取整数对和
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    typedef long long LL;
    static const int mod = 1e9 + 7;

    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1);
        for(int i = 0; i < n; i++) cnt[nums[i]]++;

        vector<int> s(mx + 1);
        for(int i = 1; i <= mx; i++) s[i] = s[i - 1] + cnt[i];

        LL res = 0;
        for(int y = 1; y <= mx; y++)
        {
            if(cnt[y])
            {
                for(int d = 1; d * y <= mx; d++)
                {
                    res += (LL)cnt[y] * d * (s[min((d + 1) * y - 1, mx)] - s[d * y - 1]);

                }
            }
        }

        return res % mod;
    }
};
// @lc code=end

