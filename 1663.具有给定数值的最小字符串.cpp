/*
 * @lc app=leetcode.cn id=1663 lang=cpp
 *
 * [1663] 具有给定数值的最小字符串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;

        for(int len = n; len >= 1; len--)
        {
            int bound = k - (len - 1) * 26;
            if(bound > 0) res += 'a' + bound - 1, k -= bound;
            else res += 'a', k -= 1;
        }

        return res;
    }
};
// @lc code=end

