/*
 * @lc app=leetcode.cn id=1770 lang=cpp
 *
 * [1770] 执行乘法运算的最大分数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size(), n = nums.size();
        vector<vector<int>> f(m + 1, vector<int>(m + 1, INT_MIN));

        f[0][0] = 0;
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; i + j <= m; j++)
            {
                if(i > 0)
                    f[i][j] = max(f[i][j], f[i - 1][j] + multipliers[i + j - 1] * nums[i - 1]);
                if(j > 0) 
                    f[i][j] = max(f[i][j], f[i][j - 1] + multipliers[i + j - 1] * nums[n - j]);
            }
        }

        int res = INT_MIN;
        for(int i = 0, j = m; i <= m; i++, j--)
        {
            res = max(res, f[i][j]);
        }

        return res;
    }
};
// @lc code=end

