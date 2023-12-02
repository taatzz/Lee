/*
 * @lc app=leetcode.cn id=2064 lang=cpp
 *
 * [2064] 分配给商店的最多商品的最小值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& q, int x, int n)
    {
        int res = 0;
        for(auto e : q)
        {
            res += (e + x - 1) / x;
        }

        return res <= n;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1, r = *max_element(q.begin(), q.end());
        
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(q, mid, n)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

