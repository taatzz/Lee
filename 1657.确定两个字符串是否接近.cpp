/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if(n1 != n2)
            return false;

        vector<int> c1(26), c2(26);

        for(int i = 0; i < n1; i++)
        {
            c1[word1[i] - 'a']++;
            c2[word2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(c1[i] == 0 && c2[i] == 0) continue;
            if(c1[i] == 0 || c2[i] == 0) return false;
        }

        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        for(int i = 0; i < 26; i++)
            if(c1[i] != c2[i]) return false;


        return true;
    }
};
// @lc code=end

