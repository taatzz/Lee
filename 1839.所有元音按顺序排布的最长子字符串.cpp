/*
 * @lc app=leetcode.cn id=1839 lang=cpp
 *
 * [1839] 所有元音按顺序排布的最长子字符串
 */

// @lc code=start
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> h = { "ae","ei","io","ou" };

    bool check(string& s, int i)
    {
        string tmp = s.substr(i - 1, 2);
        if(h.count(tmp)) return true;
        return false;
    }

    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int i = 0, res = 0;

        while(i < n)
        {
            if(word[i] == 'a')
            {
                int start = i;
                i++;
                while(i < n && (word[i] == word[i - 1] || check(word, i)))
                {
                    i++;
                }
                if(word[i - 1] == 'u')
                {
                    res = max(res, i - start);
                }
            }
            else i++;
        }

        return res;
    }
};
// @lc code=end

