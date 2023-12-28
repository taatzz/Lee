/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int cnt[30]; 
    int balancedString(string s) {
        int n = s.size(), k = n / 4;

        for(int i = 0; i < n; i++) cnt[s[i] - 'A']++;
        
        int res = n;
        for(int i = 0, j = 0; i < n; i++)
        {
            --cnt[s[i] - 'A'];
            while(cnt['Q' - 'A'] <= k && cnt['W' - 'A'] <= k && cnt['E' - 'A'] <= k
                && cnt['R' - 'A'] <= k)
            {
                res = min(res, i - j + 1);
                ++cnt[s[j++] - 'A'];
            }
        }

        return res;
    }
};
// @lc code=end

