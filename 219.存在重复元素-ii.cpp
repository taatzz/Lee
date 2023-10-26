/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> tree;
        for(int i = 0; i < nums.size(); i++)
        {
            // 滑动窗口中是否存在当前的元素
            auto it = tree.find(nums[i]);
            if(it != tree.end()) // 存在返回1
                return true;
            tree.insert(nums[i]);
            if(i >= k) // 维护k的滑动窗口
                tree.erase(nums[i - k]);
        }

        return false;
    }
};
// @lc code=end

