/*
 * @lc app=leetcode.cn id=1540 lang=cpp
 *
 * [1540] K 次操作转变字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 对于需要相同操作次数的字母都是在x + 26次操作时更改
    bool canConvertString(string s, string t, int k) {
        int n = s.size(), m = t.size();
        if(m != n) return false;

        unordered_map<int, int> h;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                int x = t[i] - s[i];
                if(x < 0) x += 26;
                h[x]++;
            }
        }
        
        for(auto e : h)
        {
            int x = e.first + 26 * (e.second - 1);
            if(x > k) return false;
        }

        return true;
    }
};
// @lc code=end

