/*
 * @lc app=leetcode.cn id=1297 lang=cpp
 *
 * [1297] 子串的最大出现次数
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int cnt[26];

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        // 定长滑动窗口，长度为上限的字符串一定时
        // 设字符串 T 在给定的字符串 S 中出现的次数为 k，那么 T 的任意一个子串出现的次数至少也为 k，
        // 即 T 的任意一个子串在 S 中出现的次数不会少于 T 本身。这样我们就可以断定，
        // 在所有满足条件且出现次数最多的的字符串中，一定有一个的长度恰好为 minSize
        int k = min(maxSize, minSize), dif = 0, res = 0;
        unordered_map<string, int> h;

        for(int i = 0; i < n; i++)
        {
            int u = s[i] - 'a';
            if(++cnt[u] == 1) dif++;
            
            if(i >= k - 1)
            {
                int j = i - k + 1;
                if(dif <= maxLetters)
                {
                    string t = s.substr(j, k);
                    if(++h[t] > res) res = h[t];
                }
                if(--cnt[s[j] - 'a'] == 0) dif--;
            }
        }

        return res;
    }
};
// @lc code=end

