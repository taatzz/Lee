/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), res = 0, cnt = 0;
        unordered_set<char> h = { 'a','e','i','o','u' };

        for(int i = 0; i < n; i++)
        {
            if(h.count(s[i])) cnt++;
            if(i >= k - 1)
            {
                int j = i - k + 1;
                res = max(res, cnt);
                if(h.count(s[j])) cnt--;
            }
        }

        return res;
    }
};
// @lc code=end

