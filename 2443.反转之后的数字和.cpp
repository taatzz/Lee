/*
 * @lc app=leetcode.cn id=2443 lang=cpp
 *
 * [2443] 反转之后的数字和
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++)
        {
            string a = to_string(i);
            string b = a;
            reverse(b.begin(), b.end());
            if(stoi(a) + stoi(b) == num) return 1;
        }

        return 0;
    }
};
// @lc code=end

