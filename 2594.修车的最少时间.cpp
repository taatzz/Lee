/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    typedef long long LL;

    bool check(vector<int>& nums, int x, int m)
    {
        long long res = 0;
        for(auto e : nums)
        {
            res += sqrt(x / e);
        }

        return res >= m;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        LL l = 1, r = (LL) cars * cars;

        while(l < r)
        {
            LL mid = (l + r) >> 1;
            if(check(ranks, mid, cars)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

