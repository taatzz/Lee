/*
 * @lc app=leetcode.cn id=898 lang=cpp
 *
 * [898] 子数组按位或操作
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int> h;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; j--)
            {
                nums[j] |= nums[i];
                h.insert(nums[j]);
            }
            h.insert(nums[i]);
        }

        return h.size();
    }
};
// @lc code=end

