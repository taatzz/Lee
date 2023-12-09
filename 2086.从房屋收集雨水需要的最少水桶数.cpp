/*
 * @lc app=leetcode.cn id=2086 lang=cpp
 *
 * [2086] 从房屋收集雨水需要的最少水桶数
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int minimumBuckets(string s) {
        int prev = -1;

        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'H')
            {
                if(prev == i - 1) continue;
                else if(i + 1 < s.size() && s[i + 1] == '.')
                {
                    res++;
                    prev = i + 1;
                }
                else if(i - 1 >= 0 && s[i - 1] == '.')
                {
                    res++;
                    prev = i - 1;
                }
                else return -1;
            }
        }

        return res;
    }
};
// @lc code=end

