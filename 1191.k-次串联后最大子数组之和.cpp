/*
 * @lc app=leetcode.cn id=1191 lang=cpp
 *
 * [1191] K 次串联后最大子数组之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& nums, int k) {
        int n = nums.size(), mod = 1e9 + 7;
        vector<int> f(n + 1);
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(k == 1)
        {
            int res = INT_MIN;
            for(int i = 0; i < n; i++)
            {
                f[i + 1] = max(f[i] + nums[i], nums[i]);
                res = max(res, f[i + 1]);
            }
            return max(res, 0);
        }
        else
        {
            f.resize(2 * n + 1);
            int res = INT_MIN;
            for(int i = 0; i < 2 * n; i++)
            {
                f[i + 1] = max(f[i] + nums[i % n], nums[i % n]);
                res = max(res, f[i + 1]);
            }
            if(sum > 0) res = (res + (k - 2) * sum) % mod;
            else res = max(0, res);
            return res;
        }
    }
};
// @lc code=end

