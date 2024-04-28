/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0) return "0";

        int k = -2;
        int x = n;
        
        string res = "";
        while(x != 0)
        {
            int mod = x % k;
            x /= k;
            if(mod < 0) 
            {
                res.push_back('0' + (mod - k));
                x++;
            }
            else res.push_back('0' + mod);
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};
// @lc code=end

