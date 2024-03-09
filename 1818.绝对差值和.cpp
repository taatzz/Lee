/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 *
 * [1818] 绝对差值和
 */

// @lc code=start
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> h(nums1.begin(), nums1.end());
        int n = nums1.size(), mod = 1e9 + 7;
        long long sum = 0, res = 0;

        for(int i = 0; i < n; i++) sum += abs(nums1[i] - nums2[i]);
        res = sum;

        for(int i = 0; i < n; i++)
        {
            int x = nums2[i];
            long long t = sum - abs(nums1[i] - nums2[i]);
            auto it = h.lower_bound(x);
            if(it == h.begin())
            {
                res = min(res, t + abs((*it) - nums2[i]));
                auto tmp = next(it);
                res = min(res, t + abs((*tmp) - nums2[i]));
            }
            else if(it == h.end())
            {
                auto tmp = prev(it);
                res = min(res, t + abs((*tmp) - nums2[i]));
            }
            else
            {
                res = min(res, t + abs((*it) - nums2[i]));
                auto tmp = next(it);
                res = min(res, t + abs((*tmp) - nums2[i]));
                tmp = prev(it);
                res = min(res, t + abs((*tmp) - nums2[i]));
            }
        }

        return res % mod;
    }
};
// @lc code=end

