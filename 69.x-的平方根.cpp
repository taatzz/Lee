// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;

        while(l < r)
        {
            int mid = (long long)(l + r + 1 * 1ll) >> 1;
            if((long long)mid * mid <= x) l = mid;
            else r = mid - 1;;
        }

        return l;
    }
};
// @lc code=end

