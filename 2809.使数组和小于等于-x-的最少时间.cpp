/*
 * @lc app=leetcode.cn id=2809 lang=cpp
 *
 * [2809] 使数组和小于等于 x 的最少时间
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int f[N][N];

    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<pair<int, int>> t;
        for(int i = 0; i < n; i++) t.push_back({nums2[i], nums1[i]});
        sort(t.begin(), t.end());

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + t[i - 1].second + t[i - 1].first * j);
        }

        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);

        for(int t = 0; t <= n; t++)
            if(s1 + s2 * t - f[n][t] <= x) return t;

        return -1;
    }
};
// @lc code=end

