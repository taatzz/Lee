/*
 * @lc app=leetcode.cn id=2744 lang=cpp
 *
 * [2744] 最大字符串配对数目
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> h;

        int res = 0;
        for(auto e : words)
        {
            if(h.count(e))
                res++;
            else
            {
                reverse(e.begin(), e.end());
                h.insert(e);
            }
        }

        return res;
    }
};
// @lc code=end

