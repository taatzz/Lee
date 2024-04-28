/*
 * @lc app=leetcode.cn id=2141 lang=cpp
 *
 * [2141] 同时运行 N 台电脑的最长时间
 */

// @lc code=start
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long l = 0, r = sum / n;

        while(l < r)
        {
            long long mid = (l + r + 1) >> 1;
            long long sum = 0;
            for(long long e : nums) sum += min(e, mid);
            if(n * mid <= sum) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

