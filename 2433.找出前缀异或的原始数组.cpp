/*
 * @lc app=leetcode.cn id=2433 lang=cpp
 *
 * [2433] 找出前缀异或的原始数组
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            res[i] = nums[i] ^ nums[i - 1];
        }

        return res;
    }
};
// @lc code=end

