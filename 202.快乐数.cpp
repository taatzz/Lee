/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    int bitsquaresum(int n)
    {
        int tmp = 0;
        while (n)
        {
            tmp += (n % 10) * (n % 10);
            n /= 10;
        }
        return tmp;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitsquaresum(slow);
            fast = bitsquaresum(fast);
            fast = bitsquaresum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};
// @lc code=end

