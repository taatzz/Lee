/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxIceCream(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= k) res++, k -= nums[i];
        }

        return res;
    }
};
// @lc code=end

