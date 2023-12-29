/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), res = 0;
        int s1 = 0, s2 = 0, l1 = 0, l2 = 0;

        for(int i = 0; i < n; i++)
        {
            s1 += nums[i];
            s2 += nums[i];

            while(l1 <= i && s1 > goal) s1 -= nums[l1++];
            while(l2 <= i && s2 >= goal) s2 -= nums[l2++];

            res += l2 - l1;
        }

        return res;
    }
};
// @lc code=end

