/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 30;
    int a[N];
    int longestSubstring(string s, int k) {
        int n = s.size();
       int res = 0;

        for(int i = 1; i <= 26; i++)
        {
            int l = 0, r = 0;
            int cnt = 0, sum = 0;
            memset(a, 0, sizeof a);
            for(; r < n; r ++)
            {
                int u = s[r] - 'a';
                a[u]++;

                if(a[u] == 1) cnt++;

                if(a[u] == k) sum++;

                while(cnt > i)
                {
                    int t = s[l ++] - 'a';
                    a[t]--;

                    if(a[t] == 0) cnt--;
                    if(a[t] == k - 1) sum--;
                }
                if(cnt == sum)  res = max(res, r - l + 1);
            }
        }

        return res;
    }
};
// @lc code=end

