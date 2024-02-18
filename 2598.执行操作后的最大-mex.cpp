/*
 * @lc app=leetcode.cn id=2598 lang=cpp
 *
 * [2598] 执行操作后的最大 MEX
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> h;

        for(auto e : nums) h[(e % k + k) % k]++;

        int res = 0;
        while(h[res % k]--) res++;

        return res;
    }
};
// @lc code=end

