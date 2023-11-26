/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */
// @lc code=start
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int a[26], b[26];
        int res = 0, cnt = 0;
        memset(a, -1, sizeof a);
        memset(b, -1, sizeof b);

        for(int i = 0; i < n; i++)
        {
            auto t = s[i] - 'A';
            cnt += i - b[t] - (b[t] - a[t]);
            res += cnt;
            a[t] = b[t], b[t] = i;
        }

        return res;
    }
};
// @lc code=end

