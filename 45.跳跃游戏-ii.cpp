;/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int res = 0x3f3f3f3f;
    int cnt = 0;
    void dfs(vector<int>& nums, int x)
    {
        if(x == nums.size())
        {
            res = min(res, cnt);

            return;
        }

        for (int i = 1; i <= nums[x]; i++)
        {
            cnt++;
            dfs(nums, x + i);
            cnt--;
        }
    }

    int jump(vector<int>& nums) {
        return res;
    }
};
// @lc code=end

