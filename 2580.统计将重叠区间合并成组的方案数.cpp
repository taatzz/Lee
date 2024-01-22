/*
 * @lc app=leetcode.cn id=2580 lang=cpp
 *
 * [2580] 统计将重叠区间合并成组的方案数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] <= b[0];
    }
    static const int mod = 1e9 + 7;

    int countWays(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        int n = nums.size();

        int start = INT_MIN, end = INT_MIN;
        int res = 1;
        for(int i = 0; i < n; i++)
        {
            if(end < nums[i][0])
            {
                if(end != INT_MIN) res =  res * 2 % mod;
                start = nums[i][0], end = nums[i][1];
            }
            else end = max(end, nums[i][1]);
        }
        if(end != INT_MIN) res = res * 2 % mod;

        return res;
    }
};
// @lc code=end

