/*
 * @lc app=leetcode.cn id=1915 lang=cpp
 *
 * [1915] 最美子字符串的数目
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string s) {
        unordered_map<int, int> h;
        h[0] = 1;

        int n = s.size(), sum = 0;
        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            sum ^= 1 << (s[i] - 'a');
            res += h[sum];

            for(int j = 0; j < 10; j++)
            {
                res += h[(sum ^ (1 << j))];
            }
            h[sum]++;
        }

        return res;
    }
};
// @lc code=end

