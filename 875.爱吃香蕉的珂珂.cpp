/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int check(vector<int>& p, int x)
    {
        int res = 0;
        for(auto e : p)
        {
            if(e % x == 0)
                res += e / x;
            else
                res += e / x + 1;
        }
        
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *(max_element(piles.begin(), piles.end()));

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(piles, mid) <= h) r = mid;
            else r = mid + 1;
        }

        return l;
    }
};
// @lc code=end

