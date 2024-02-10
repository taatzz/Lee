/*
 * @lc app=leetcode.cn id=2771 lang=cpp
 *
 * [2771] 构造最长非递减子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // f[i][0] 表示以nums1结尾的最长非递减子数组
        // f[i][1] 表示以nums2结尾的最长非递减子数组
        vector<vector<int>> f(n, vector<int>(2));
        f[0][0] = 1, f[0][1] = 1;
        int res = 1;

        for(int i = 1; i < n; i++)
        {
            f[i][0] = max(nums1[i] >= nums1[i - 1] ? f[i - 1][0] + 1 : 1, 
                          nums1[i] >= nums2[i - 1] ? f[i - 1][1] + 1 : 1);
            f[i][1] = max(nums2[i] >= nums1[i - 1 ] ? f[i - 1][0] + 1 : 1,
                          nums2[i] >= nums2[i - 1] ? f[i - 1][1] + 1 : 1);

            res = max({res, f[i][0], f[i][1]});
        }

        return res;
    }
};
// @lc code=end

