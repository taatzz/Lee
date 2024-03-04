/*
 * @lc app=leetcode.cn id=2680 lang=cpp
 *
 * [2680] 最大或值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int right[N];

    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = n - 1; i >= 0; i--) right[i] = right[i + 1] | nums[i];

        long long res = 0, left = 0;
        for(int i = 0; i < n; i++)
        {
            res = max(res, (left | ((long long)nums[i] << k) | right[i + 1]));
            left |= nums[i];
        }

        return res;
    }
};
// @lc code=end

