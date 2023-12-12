/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int t = sum - x;
        int res = -1, cnt = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            cnt += nums[i];
            while(cnt > t)
            {
                cnt -= nums[j++];
            }
            if(cnt == t)
                res = max(res, i - j + 1);
        }

        return res < 0 ? -1 : n - res;
    }
};
// @lc code=end

