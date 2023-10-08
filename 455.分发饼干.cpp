/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;

        auto index = s.rbegin();
        for(auto it = g.rbegin(); it != g.rend(); it++)
        {
            if(index != s.rend() && *index >= *it)
            {
                res++;
                index++;
            }
        }

        // int j = s.size() - 1;
        // for(int i = g.size() - 1; i >=0; i--)
        // {
        //     if(j >= 0 && s[j] >= g[i])
        //     {
        //         j--;
        //         res++;
        //     }
        // }
        return res;
    }
};
// @lc code=end

