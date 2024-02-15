/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();

        for(int i = 0; i < m; i++)
        {
            if(nums[i][0] == 0)
            {
                for(int j = 0; j < n; j++)
                {
                    nums[i][j] ^= 1;
                }
            }
        }

        vector<int> col(n);
        for(int j = 0; j < n; j++)
        {
            int cnt = 0;
            for(int i = 0; i < m; i++)
            {
                cnt += nums[i][j];
            }
            col[j] = cnt;
        }

        int res = 0, a = 1;
        for(int j = n - 1; j >= 0; j--)
        {
            if(col[j] <= m / 2)
            {
                res += a * (m - col[j]);
            }
            else res += a * col[j];
            a *= 2;
        }


        return res;
    }
};
// @lc code=end

