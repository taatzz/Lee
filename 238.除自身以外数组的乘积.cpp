/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, 1);
        for(int i = n - 2; i >= 0; i--) right[i] = right[i + 1] * nums[i + 1];

        vector<int> res(n);
        int pre = 1;
        for(int i = 0; i < n; i++)
        {
            res[i] = pre * right[i];
            pre *= nums[i]; 
        }

        return res;
    }
};
// @lc code=end

