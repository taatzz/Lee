/*
 * @lc app=leetcode.cn id=2167 lang=cpp
 *
 * [2167] 移除所有载有违禁货物车厢所需的最少时间
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> right(n + 1);

        for(int i = n - 1; i >= 0; i--) 
            if(s[i] == '1') right[i] = min(right[i + 1] + 2, n - i);
            else right[i] = right[i + 1];

        int res = right[0];
        int pre = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                pre = min(pre + 2, i + 1);
                res = min(res, pre + right[i + 1]);
            }
        }


        return res;
    }
};
// @lc code=end

