/*
 * @lc app=leetcode.cn id=2781 lang=cpp
 *
 * [2781] 最长合法子字符串的长度
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& words) {
        unordered_set<string> h;
        for(auto& e : words) h.insert(e);

        int n = word.size(), res = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            for(int k = i; k >= j && i - k <= 10; k--)
            {
                if(h.count(word.substr(k, i - k + 1))) 
                {
                    j = k + 1;
                    break;
                }
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};
// @lc code=end

