/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prediff = 0, curdiff = 0;
        int res = 1;
        /* 1.
               2 2 2
            1         1
           2.
              2 
             1 prediff = 0 curdiff > 0 res++
            3.
                    3
              2 2 2
            1
            res = 2 prediff不能实时更新，当有峰值时更新prediff当curdiff与prediff不相同时更新
        */
        // 最后一个元素默认符合摆动序列，所以res = 1.
        for(int i = 0; i < nums.size() - 1; i++)
        {
            curdiff = nums[i + 1] - nums[i];
            if((prediff <= 0 && curdiff > 0) || (prediff >= 0 && curdiff < 0) )
            {
                prediff = curdiff;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

