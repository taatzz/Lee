/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int i = 0, j = 0;
        for(j; j < s2.size(); j++)
        {
            if(s1[i] == s2[j]) i++;
        }

        return i == s1.size();
    }
};
// @lc code=end

