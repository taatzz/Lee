/*
 * @lc app=leetcode.cn id=2840 lang=cpp
 *
 * [2840] 判断通过操作能否让字符串相等 II
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt1(2, vector<int>(26, 0));
        vector<vector<int>> cnt2(2, vector<int>(26, 0));

        int n = s1.size();
        for(int i = 0; i < n; i++)
        {
            cnt1[i % 2][s1[i] - 'a']++;
            cnt2[i % 2][s2[i] - 'a']++;
        }   

        for(int i = 0; i < 26; i++)
            if((cnt1[0][i] != cnt2[0][i]) || (cnt1[1][i] != cnt2[1][i])) return false;
        return true;
    }
};
// @lc code=end

