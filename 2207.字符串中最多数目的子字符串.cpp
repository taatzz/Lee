/*
 * @lc app=leetcode.cn id=2207 lang=cpp
 *
 * [2207] 字符串中最多数目的子字符串
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 前后缀分解
    long long maximumSubsequenceCount(string s, string pattern) {
        int n = s.size();

        // 后缀分解
        vector<int> right(n + 1);

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == pattern[1]) right[i] = right[i + 1] + 1;
            else right[i] = right[i + 1];
        }

        long long res = 0;
        int cnt = 0; // 统计前缀

        for(int i = 0; i < n; i++)  
        {
            if(s[i] == pattern[0]) 
            {
                cnt++;
                // 如果目标字符串的两个字母相同则不能重复计算按照后一个字符的后缀计算答案
                if(pattern[0] == pattern[1])
                    res += right[i + 1];
                else res += right[i];
            }
        }

        // 最后插入字符，因为是子序列所以应该选择出现次数少的进行插入，插入的字符可以插入到最前或者最后所以答案直接累加前缀或者后缀
        if(cnt < right[0]) res += right[0];
        else res += cnt;

        return res;
    }
};
// @lc code=end

