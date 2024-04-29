/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int minCapability(vector<int>& nums, int k) {
        int r = *max_element(nums.begin(), nums.end());
        int l = 0;

        auto check = [&](int x)->bool
        {
            int n = nums.size(), cnt = 0;

            for(int i = 0; i < n; i++)
            {
                if(nums[i] <= x) cnt++, i++;
            }

            return cnt >= k;
        };

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

