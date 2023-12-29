/*
 * @lc app=leetcode.cn id=2616 lang=cpp
 *
 * [2616] 最小化数对的最大差值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int x, int k)
    {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i ++)
        {
            if(i + 1 < n && nums[i + 1] - nums[i] <= x)
            {
                cnt++, i++;
            }
        }

        return cnt >= k;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums[n - 1] - nums[0];
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, mid, p)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

