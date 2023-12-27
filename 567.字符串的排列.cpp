/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 30;
    int cnt1[N], cnt2[N];

    bool check()
    {
        for(int i = 0; i < 26; i++)
        {
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        for(int i = 0; i < s1.size(); i++) cnt1[s1[i] - 'a']++;
        int k = s1.size();
        for(int i = 0; i < s2.size(); i++)
        {
            cnt2[s2[i] - 'a']++;
            if(i >= k - 1)
            {
                if(check()) return true;
                int j = i - k + 1;
                cnt2[s2[j] - 'a']--;
            }
        }

        return false;
    }
};
// @lc code=end

