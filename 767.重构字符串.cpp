/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PCI;
    PCI cnt[26];

    static bool cmp(PCI& a, PCI& b)
    {
        return a.first > b.first;
    }

    string reorganizeString(string s) {
        int n = s.size(), idx = 0;

        for(int i = 0; i < n; i++)
        {
            int x = s[i] - 'a';
            if(cnt[x].first == 0) idx++;
            cnt[x].first++;
            cnt[x].second = s[i];
        }

        string res = s;
        sort(cnt, cnt + 26, cmp);
        if(cnt[0].first * 2 - 1 > s.size()) return "";
        
        int index = 0;
        for(int i = 0; i < idx; i++)
        {
            while(cnt[i].first --)
            {
                res[index] = cnt[i].second;
                index += 2;
                if(index >= s.size()) index = 1;
            }
        }

        return res;
    }
};
// @lc code=end

