/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 *
 * [1358] 包含所有三种字符的子字符串数目
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int cnt[3];
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0;

        for(int i = 0, j = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;

            while(cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1)
            {
                res += n - i;
                cnt[s[j++] - 'a'] --;
            }
        }

        return res;
    }
};
// @lc code=end

