/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i = 0; i < n - 1; i ++)
        {
            if((i - res) % 2 == 0 && nums[i] == nums[i + 1])
                res++;
        }
        if((n - res) % 2 == 0) return res;
        else return res + 1;
    }
};
// @lc code=end

