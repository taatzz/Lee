/*
 * @lc app=leetcode.cn id=2453 lang=cpp
 *
 * [2453] 摧毁一系列目标
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        for(auto& e : nums) h[e % k] ++;

        int res = nums[0], mx = h[nums[0] % k];

        for(int x : nums)
        {
            int t = h[x % k];
            if(t > mx || (t == mx && x < res)) res = x, mx = t;
        }

        return res;
    }
};
// @lc code=end

