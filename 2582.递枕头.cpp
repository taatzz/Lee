/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        if(time < n)
            return 1 + time;
        
        int tmp = 0;
        while(time >= n)
        {
            time -= n - 1;
            tmp++;
        }
        if(tmp % 2)
            return n - time;
        else
            return 1 + time;
    }
};
// @lc code=end

