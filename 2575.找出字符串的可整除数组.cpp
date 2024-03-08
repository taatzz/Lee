/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 *
 * [2575] 找出字符串的可整除数组
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string s, int m) {
       int n = s.size();

       vector<int> res(n);
       long long t = 0;
       for(int i = 0; i < n; i++)
       {
           t = (t * 10 + (s[i] - '0')) % m;
           if(t == 0) res[i] = 1;
       }

       return res;
    }
};
// @lc code=end

