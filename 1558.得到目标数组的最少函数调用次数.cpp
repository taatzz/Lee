/*
 * @lc app=leetcode.cn id=1558 lang=cpp
 *
 * [1558] 得到目标数组的最少函数调用次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0, mx = 0;
        for(auto e : nums)
        {
            mx = max(mx, e);
            for(int i = 0; i < 32; i++)
            {
                if((e & (1 << i)) == (1 << i))
                    cnt++;
            }
        }

        for(int i = 31; i >= 0; i--)
            if((mx & (1 << i)) == (1 << i))
            {
                cnt += i;
                break;
            }        

        return cnt;
    }
};
// @lc code=end

