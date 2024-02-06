/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        // f[i][d] 表示以i结尾的公差为d的最长等差数列
        vector<vector<int>> f(n, vector<int>(1010, 1));

        int res = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                // 加500防止出现负数的情况
                int d = nums[i] - nums[j] + 500;
                f[i][d] = max(f[i][d], f[j][d] + 1);
                res = max(res, f[i][d]);
            }
        }

        return res;
    }
};
// @lc code=end

