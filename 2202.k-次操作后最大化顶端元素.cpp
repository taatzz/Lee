/*
 * @lc app=leetcode.cn id=2202 lang=cpp
 *
 * [2202] K 次操作后最大化顶端元素
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k % 2 == 1) return -1;
        else if(n == 1 && k % 2 == 0) return nums[0];

        if(k > n) return *max_element(nums.begin(), nums.end());

        int res = -1;
        for(int i = 0; i < min(n, k + 1); i++)
        {
            if(i != k - 1)
                res = max(res, nums[i]);
        }

        return res;
    }
};
// @lc code=end

