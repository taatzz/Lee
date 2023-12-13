// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;

        int i = 0, j = 0, sum = 1, res = 0;
        for(; i < n; i++)
        {
            sum *= nums[i];
            while(sum >= k) sum /= nums[j++];
            res += i - j + 1;
        }

        return res;
    }
};
// @lc code=end

