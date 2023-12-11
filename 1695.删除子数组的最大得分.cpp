/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int s[N], cnt[N];

    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        int res = 0, i = 0, j = 0;
        for(; i < n; i++)
        {
            cnt[nums[i]]++;
            if(cnt[nums[i]] > 1)
            {
                res = max(res, s[i] - s[j]);
                while(j < i && cnt[nums[i]] > 1) cnt[nums[j++]] --;
            }
        }
        res = max(res, s[i] - s[j]);

        return res;
    }
};
// @lc code=end

