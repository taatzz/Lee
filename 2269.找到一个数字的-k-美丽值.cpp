/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 *
 * [2269] 找到一个数字的 K 美丽值
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);

        int res = 0;
        for(int i = k - 1; i < s.size(); i++)
        {
            int j = i - k + 1;
            string t = s.substr(j, k);
            int tmp = stoi(t);
            if(tmp && num % tmp == 0) res++;
        }

        return res;
    }
};
// @lc code=end

