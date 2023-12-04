/*
 * @lc app=leetcode.cn id=1898 lang=cpp
 *
 * [1898] 可移除字符的最大数目
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(string& s, string& p, vector<int>& nums, int mid)
    {
        int i = 0, j = 0;
        int n = s.size();
        vector<int> st(n, 1);
        for(int i = 0; i < mid; i++) st[nums[i]] = 0;

        for(; i < s.size(); i++)
        {
            if(s[i] == p[j] && st[i]) j++;
            if(j == p.size()) return 1;
        }


        return 0;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int l = 0, r = n;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(s, p, removable, mid)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

