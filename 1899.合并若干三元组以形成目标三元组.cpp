/*
 * @lc app=leetcode.cn id=1899 lang=cpp
 *
 * [1899] 合并若干三元组以形成目标三元组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool t[3];
    // 同一个三元组多次选择没有意义
    // max操作我们只能选择小于目标数值的三元组，所以如果小于目标值的元素中存在目标值就一定可以找到
    bool mergeTriplets(vector<vector<int>>& nums, vector<int>& target) {

        for(auto e : nums)
        {
            if(e[0] <= target[0] && e[1] <= target[1] && e[2] <= target[2])
            {
                t[0] = t[0] || e[0] == target[0];
                t[1] = t[1] || e[1] == target[1];
                t[2] = t[2] || e[2] == target[2];
            }
        }

        return t[0] && t[1] && t[2];
    }
};
// @lc code=end

