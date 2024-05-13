/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n + 1);

        int a = 0, b = 0;
        for(int i = 1; i < n; i += 2) a ^= nums[i];
        for(int i = 1; i <= n + 1; i++) b ^= i;

        res[0] = a ^ b;
        for(int i = 0; i < n; i++)
        {
            res[i + 1] = res[i] ^ nums[i];
        }

        return res;
    }
};
// @lc code=end

