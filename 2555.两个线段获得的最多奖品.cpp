/*
 * @lc app=leetcode.cn id=2555 lang=cpp
 *
 * [2555] 两个线段获得的最多奖品
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximizeWin(vector<int>& nums, int k) {
        int n = nums.size();
        if(k + k + 1 >= nums[n - 1] - nums[0] + 1) return n;  

        int res = 0;
        vector<int> pre(n + 1); // 以i结尾和前面的线段中可以获得的最多奖品数。
        for(int i = 0; i < n; i++)
        {
            int r = nums[i] + k;
            int idx = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
            pre[idx] = max(pre[idx], idx - i);
        }
        // 更新前缀最大值
        for(int i = 0; i < n; i++)
        {
            pre[i + 1] = max(pre[i + 1], pre[i]);
        }

        for(int i = 1; i <= n; i++)
        {
            int r = nums[i - 1] + k;
            int idx = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
            res = max(res, pre[i - 1] + idx - i + 1);
        }

        return res;
    }
};
// @lc code=end

