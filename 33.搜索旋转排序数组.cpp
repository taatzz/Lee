// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int l = 0, r = n;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(nums[0] <= nums[mid]) l = mid;
            else r = mid - 1;
        }

        if(target >= nums[0])
        {
            l = 0;
        }
        else
        {
            l = r + 1;
            r = n;
        }

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return nums[r] == target ? r : -1;
    }
};
// @lc code=end

