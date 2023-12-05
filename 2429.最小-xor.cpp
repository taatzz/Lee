/*
 * @lc app=leetcode.cn id=2429 lang=cpp
 *
 * [2429] 最小 XOR
 */

// @lc code=start
class Solution {
public:

    int lowbit(int x)
    {
        return x & -x;
    }

    int minimizeXor(int num1, int num2) {
        int t1 = num1, t2 = num2;
        int n1 = 0, n2 = 0;
        for(; t1; t1 -= lowbit(t1))
            n1 ++;
        for(; t2; t2 -= lowbit(t2))
            n2 ++;

        int res = 0;
        if(n1 == n2) return num1;
        else if(n1 < n2)
        {
            int n = n2 - n1;
            for(int i = 0; i < 32; i++)
            {
                if(((num1 >> i) & 1) == 0)
                {
                    res |= (num1 | (1 << i));
                    n--;
                }
                if(!n) break;
            }

            return res;
        }
        else 
        {
            for(int i = 31; i >= 0; i--)
            {
                if((num1 >> i) & 1)
                {
                    res += (1 << i);
                    n2--;
                }
                if(!n2)break;
            }
        }

        return res;
    }
};
// @lc code=end

