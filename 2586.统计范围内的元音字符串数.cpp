/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int n = words.size();
        set<char> s = { 'a','e','i','o','u' };

        int res = 0;
        for(int i = left; i <= right; i++)
        {
            int length = words[i].size() - 1;
            if(s.find(words[i][0]) != s.end() && s.find(words[i][length]) != s.end())
                res++;
        }

        return res;
    }
};
// @lc code=end

