/*
 * @lc app=leetcode.cn id=1930 lang=cpp
 *
 * [1930] 长度为 3 的不同回文子序列
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    // 枚举两边的字符，当找到两个相同的字符时，两个字符间的字符种类数就是答案
    int countPalindromicSubsequence(string a) {
        int n = a.size();
        unordered_set<char> h;
        for(auto e : a) h.insert(e);

        int res = 0;
        for(auto e : h)
        {
            int l = 0, r = n - 1;
            while(l <= r && a[l] != e) l++;
            while(l <= r && a[r] != e) r--;

            if(r - l <= 1) continue;

            unordered_set<char> tmp;
            for(int i = l + 1; i < r; i++)
                tmp.insert(a[i]);
            
            res += tmp.size();
        }

        return res;
    }
};
// @lc code=end

