/*
 * @lc app=leetcode.cn id=1737 lang=cpp
 *
 * [1737] 满足三条件之一需改变的最少字符数
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 30;
    int cnt1[N], cnt2[N];
    int s1[N], s2[N];

    int minCharacters(string a, string b) {
        for(auto& e : a) cnt1[e - 'a']++;
        for(auto& e : b) cnt2[e - 'a']++;

        for(int i = 1; i <= 26; i++) s1[i] = s1[i - 1] + cnt1[i - 1];
        for(int i = 1; i <= 26; i++) s2[i] = s2[i - 1] + cnt2[i - 1];

        int res = INT_MAX;
        
        for(int i = 0; i < 26; i++)
        {
            if(i == 0) continue;
            int num1 = s1[26] - s1[i], num2 = s2[i];
            res = min({num1 + num2, res});

            num1 = s1[i], num2 = s2[26] - s2[i];
            res = min({num1 + num2, res});
        }

        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                res = min(res, s1[26] - cnt1[i] + s2[26] - cnt2[j]);
            }
        }

        return res;
    }
};
// @lc code=end

