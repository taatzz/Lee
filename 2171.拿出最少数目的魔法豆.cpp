/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 *
 * [2171] 拿出最少数目的魔法豆
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];

    long long minimumRemoval(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        long long res = s[n];
        for(int i = 0; i < n; i++)
        {
            long long l = s[i];
            long long r = s[n] - s[i + 1] - (long long)nums[i] * (n - i - 1);
            res = min(res, l + r);
        }

        return res;
    }
};
// @lc code=end

