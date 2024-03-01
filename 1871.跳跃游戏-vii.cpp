/*
 * @lc app=leetcode.cn id=1871 lang=cpp
 *
 * [1871] 跳跃游戏 VII
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n), pre(n);

        for(int i = 0; i < minJump; i++) pre[i] = 1;

        for(int i = minJump; i < n; i++)
        {
            int l = i - maxJump, r = i - minJump;
            if(s[i] == '0')
            {
                int st = pre[r] - (l <= 0 ? 0 : pre[l - 1]);
                f[i] = (st != 0);
            }
            pre[i] = pre[i - 1] + f[i];
        }

        return f[n - 1];
    }
};
// @lc code=end

