/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int s[N];

    bool check(int n, int x, int k)
    {
        for(int i = x - 1; i < n; i++)
        {
            int j = i - x + 1;
            int t = s[i + 1] - s[j];
            if(x - t <= k) return true;
        }
        return false;
    }

    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1, r = n;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(n, mid, k)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

