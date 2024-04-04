/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1)
        {
            string res = s, t = s;
            for(int i = 0; i < s.size() - 1; i++)
            {
                char c = t[0];
                for(int j = 1; j < t.size(); j++) t[j - 1] = t[j];
                t[t.size() - 1] = c;
                res = min(res, t);
            }
            
            return res;
        }
        sort(s.begin(), s.end());

        return s;
    }
};
// @lc code=end

