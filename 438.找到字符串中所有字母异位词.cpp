/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
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

    vector<int> findAnagrams(string s, string p) {
        for(int i = 0; i < p.size(); i++) cnt1[p[i] - 'a']++;

        int k = p.size();
        vector<int> res;

        for(int i = 0; i < s.size(); i++)
        {
            cnt2[s[i] - 'a']++;
            if(i >= k - 1)
            {
                int j = i - k + 1;
                if(check())
                    res.push_back(j);
                cnt2[s[j] - 'a']--;
            }
        }

        return res;
    }
};
// @lc code=end

