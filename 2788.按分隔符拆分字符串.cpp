/*
 * @lc app=leetcode.cn id=2788 lang=cpp
 *
 * [2788] 按分隔符拆分字符串
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char c) {
        vector<string> res;

        for(auto e : words)
        {
            int i = 0, n = e.size();
            while(i < n)
            {
                if(e[i] == c)
                {
                    i++;
                    continue;
                }
                int start = i;
                i++;
                while(i < n && e[i] != c) i++;
                res.push_back(e.substr(start, i - start));
                i++;
            }
        }

        return res;
    }
};
// @lc code=end

