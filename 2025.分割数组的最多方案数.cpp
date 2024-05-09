/*
 * @lc app=leetcode.cn id=2025 lang=cpp
 *
 * [2025] 分割数组的最多方案数
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    typedef long long LL;
    static const int N = 100010;
    LL s[N];

    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<LL, int> pre, suf;
        for(int i = 1; i <= n; i++) 
        {
            s[i] = s[i - 1] + nums[i - 1];
        }
        for(int i = 1; i < n; i++) suf[s[i]]++;
        LL sum = s[n];

        int res = 0;
        if(sum % 2 == 0) res = suf[sum / 2];

        for(int i = 0; i < n; i++)
        {
            int d = k - nums[i];
            if((sum + d) % 2 == 0)
            {
                res = max(res, pre[(sum + d) / 2] + suf[(sum - d) / 2]);
            }
            pre[s[i + 1]]++;
            suf[s[i + 1]]--;
        }

        return res;
    }
};
// @lc code=end

