/*
 * @lc app=leetcode.cn id=2587 lang=cpp
 *
 * [2587] 重排数组以得到最大前缀分数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long res = 0, sum = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            sum += nums[i];
            if(sum > 0) res++;
        }

        return res;
    }
};
// @lc code=end

