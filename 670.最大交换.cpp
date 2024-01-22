/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        int n = s.size();
        int mx = n - 1, p = -1, q = 0;
        for(int i = n - 2; i >= 0; i--)
        {
            if(s[i] > s[mx])
                mx = i;
            else if(s[i] < s[mx])
            {
                p = i;
                q = mx;
            }
        }
        if(p == -1) return num;
        swap(s[p], s[q]);

        return stoi(s);
    }
};
// @lc code=end

