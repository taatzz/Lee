/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& nums, int mean, int n) {
        int sum = accumulate(nums.begin(), nums.end(), 0), m = nums.size();

        int x = (m + n) * mean - sum;

        int mn = n, mx = n * 6;
        if(x < mn || x > mx) return {};
        vector<int> res(n, x / n);
        int t = x % n;
        for(int i = 0; i < res.size() && t; i++, t--) res[i] += 1;

        return res;
    }
};
// @lc code=end

