/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& p, int x, int k)
    {
        int res = 1;
        int pre = p[0];

        for(int i = 1; i < p.size(); i++)
        {
            if(p[i] - pre >= x) 
            {
                res++;
                pre = p[i];
            }
        }

        return res >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        int max_num = 0;
        for(auto e : price) max_num = max(e, max_num);

        sort(price.begin(), price.end());

        int l = 0, r = max_num;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(price, mid, k)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

