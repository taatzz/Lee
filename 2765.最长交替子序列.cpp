/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 *
 * [2765] 最长交替子序列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, res = 0;
        while(i < n)
        {
            if(i + 1 < n && nums[i + 1] - nums[i] == 1)
            {
                int start = i;
                i++;
                int j = 1;
                while(i < n && nums[i] - nums[i - 1] == j)
                {
                    if(j == 1) j = -1;
                    else j = 1;
                    i++;
                }
                if(i - start > 1)
                {
                    res = max(res, i - start);
                    // 可能会有重叠的部分
                    i = i - 1;
                }
            }
            else i++;
        }

        return res;
    }
};
// @lc code=end

