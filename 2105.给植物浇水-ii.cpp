/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 *
 * [2105] 给植物浇水 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& nums, int a, int b) {
        int n = nums.size(), res = 0;

        int l = 0, r = n - 1, x1 = a, x2 = b;
        while(l <= r)
        {
            if(l == r)
            {
                if(max(x1, x2) < nums[l])
                    res++;
                break;
            }
            if(x1 < nums[l])
            {
                res ++;
                x1 = a;
            }
            if(x2 < nums[r])
            {
                res ++;
                x2 = b;
            }
            x1 -= nums[l];
            x2 -= nums[r];
            l++;
            r--;
        }

        return res;
    }
};
// @lc code=end

