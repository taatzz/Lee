/*
 * @lc app=leetcode.cn id=2317 lang=cpp
 *
 * [2317] 操作后的最大异或和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i = 0; i < n; i++)
            res |= nums[i];

        return res;
    }
};
// @lc code=end

