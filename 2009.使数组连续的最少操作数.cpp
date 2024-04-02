/*
 * @lc app=leetcode.cn id=2009 lang=cpp
 *
 * [2009] 使数组连续的最少操作数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> tmp = nums;
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int t = nums.size() - tmp.size();
        int res = INT_MAX;

        int n = nums.size();
        for(int i = 0; i < tmp.size(); i++)
        {
            int x = n - 1 + tmp[i];
            int idx = tmp.end() - upper_bound(tmp.begin(), tmp.end(), x);

            res = min(res, (int)(t + i + idx));
        }

        return res;
    }
};
// @lc code=end

