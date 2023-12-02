/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 *
 * [1760] 袋子里最少数目的球
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int x, int n)
    {
        int cnt = 0;
        for(auto e : nums)
        {
            // 小于最大值的球不需要操作
            if(e > x)
            {
                // 能直接除尽的只需要 e/x - 1, 不能除尽的就是e/x
                // if(e % x) cnt +=  e / x;
                // else cnt += e / x - 1;
                cnt += (e - 1) / x;
            }
        }

        return cnt <= n;
    }

    int minimumSize(vector<int>& nums, int n) {
        int l = 1, r = *max_element(nums.begin(), nums.end());

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, mid, n)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

