/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] 最小化数组中的最大值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> nums, int x)
    {
        int n = nums.size();
        long long res = 0;

        for(int i = n - 1; i > 0; i--)
        {
            if(nums[i] + res >= x) res = res + nums[i] - x;
            else res = 0;
        }

        return (long)nums[0] + res <= x;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int max_num = 0;
        for(auto e : nums) max_num = max(e, max_num);

        int l = 0, r = max_num;

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, mid)) r = mid;
            else l = mid + 1;;
        }

        return r;
    }
};
// @lc code=end

