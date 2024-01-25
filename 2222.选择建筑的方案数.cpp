/*
 * @lc app=leetcode.cn id=2222 lang=cpp
 *
 * [2222] 选择建筑的方案数
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size(), prev = 0;
        vector<int> zero_right(n);
        long long res = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '1') zero_right[i] = prev;
            else prev ++;
        }
        prev = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0') prev ++;
            else res += prev * zero_right[i];
        }

        prev = 0;
        vector<int> one_right(n);
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '1') prev++;
            else one_right[i] = prev;
        }
        prev = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0') res += prev * one_right[i];
            else prev++;
        }

        return res;
    }
};
// @lc code=end

