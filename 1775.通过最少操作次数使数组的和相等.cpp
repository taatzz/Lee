/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size()) return -1;

        int dif = accumulate(nums2.begin(), nums2.end(), 0) - accumulate(nums1.begin(), nums1.end(), 0);
        if(dif < 0)
        {
            dif = -dif;
            swap(nums1, nums2);
        }

        int cnt[6]{};
        for(int e : nums1) cnt[6 - e]++;
        for(int e : nums2) cnt[e - 1]++;

        int res = 0;
        for(int i = 5;; i--)
        {
            if(i * cnt[i] >= dif) return res + (dif + i - 1) / i;
            res += cnt[i];
            dif -= cnt[i] * i;
        }
    }
};
// @lc code=end

