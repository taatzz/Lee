/*
 * @lc app=leetcode.cn id=2640 lang=cpp
 *
 * [2640] 一个数组所有前缀的分数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            mx = max(nums[i], mx);
            res[i] = mx + nums[i];
        }

        for(int i = 0; i < n - 1; i++) res[i + 1] += res[i];

        return res;
    }
};
// @lc code=end

