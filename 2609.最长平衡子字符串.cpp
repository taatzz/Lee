/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 */

// @lc code=start
#include <string>
#include <iostream>

using namespace std;

// class Solution {
// public:
//     int findTheLongestBalancedSubstring(string s) {
//         int res = 0, pre = 0, cur = 0;

//         for(int i = 0; i < s.size(); i++)
//         {
//             cur++;
//             if(i == s.size() - 1 || s[i] != s[i+1])
//             {
//                 if(s[i] == '1')
//                 {
//                     res = max(res, min(cur, pre) * 2);
//                 }
//                 pre = cur;
//                 cur = 0;
//             }
//         }

//         return res;
//     }
// };
// @lc code=end



class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size(), idx = 0, ans = 0;
        while (idx < n) {
            int a = 0, b = 0;
            while (idx < n && s[idx] == '0') idx++, ++a;
            while (idx < n && s[idx] == '1') idx++, ++b;
            ans = max(ans, min(a, b) * 2);
        }
        return ans;
    }
};
