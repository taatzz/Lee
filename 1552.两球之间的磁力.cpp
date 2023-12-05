/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 *
 * [1552] 两球之间的磁力
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int x, int m)
    {
        int n = nums.size();
        int res = 1;
        int i = 0, j = 0;
        for(; i < n; i++)
        {   
            if(nums[i] - nums[j] >= x) 
            {
                j = i;
                res++;
            }
        }

        return res >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int l = 0, r = position[n - 1];
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(position, mid, m)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

