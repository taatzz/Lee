/*
 * @lc app=leetcode.cn id=2785 lang=cpp
 *
 * [2785] 将字符串中的元音字母排序
 */

// @lc code=start
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        set<char> h = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        vector<char> cnt;
        for(int i = 0; i < n; i++)
        {
            if(h.count(s[i])) cnt.push_back(s[i]);
        }
        sort(cnt.begin(), cnt.end(), [](char a, char b) { return a < b; });
        for(int i = 0, j = 0; i < n; i++)
        {
            if(h.count(s[i])) s[i] = cnt[j++];
        }

        return s;
    }
};
// @lc code=end

