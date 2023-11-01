/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r && nums[l] == nums[r]) r--;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        int idx = n;
        if (nums[r] >= nums[0] && r + 1 < n) idx = r + 1;

        // 第二次二分，找目标值
        int ans = find(nums, 0, idx - 1, t);
        if (ans != -1) return true;
        ans = find(nums, idx, n - 1, t);
        return ans != -1;
    }

    int find(vector<int>& nums, int l, int r, int t) {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r] == t ? r : -1;
    }
};
// @lc code=end

