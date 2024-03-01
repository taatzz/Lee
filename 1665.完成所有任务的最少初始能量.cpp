/*
 * @lc app=leetcode.cn id=1665 lang=cpp
 *
 * [1665] 完成所有任务的最少初始能量
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] - a[0] > b[1] - b[0];
    }

    bool check(vector<vector<int>>& nums, int x)
    {
        int n = nums.size();
        int k = x;

        for(int i = 0; i < n; i++)
        {
            if(k < nums[i][1] || k < nums[i][0]) return 0;
            k -= nums[i][0];
        }
        return 1;
    }

    int minimumEffort(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        int l = 1, r = 1e9;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

