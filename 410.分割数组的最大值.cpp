/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int x, int k)
    {
        int cnt = 1;
        int sum = 0;
        for(auto e : nums)
        {
            if(sum + e <= x)
                sum += e;
            else
            {
                if(cnt ++ == k)    
                    return false;
                sum = e;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 左边界为数组中的最大元素
        int l = *max_element(nums.begin(), nums.end());
        int r = sum;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, mid, k)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

