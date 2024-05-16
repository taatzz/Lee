/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        auto check = [&](long long x)->bool
        {
            long long cnt = 0, i = 0, j = 0;
            while(i < n)
            {
                while(j + 1 < n && nums[j + 1] - nums[i] <= x) j++;
                cnt += j - i;
                i++;
            }

            return cnt >= k;
        };

        long long l = 0, r = 1e6 + 10;
        while(l < r)
        {
            long long mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }

        return r;
    }
};
// @lc code=end

