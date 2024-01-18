/*
 * @lc app=leetcode.cn id=1253 lang=cpp
 *
 * [1253] 重构 2 行二进制矩阵
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int a, int b, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(2, vector<int>(n));

        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(!nums[i]) continue;
            if(nums[i] == 2)
            {
                if(a == 0 || b == 0)
                {
                    flag = false;
                    break;
                }
                a--, b--;
                res[0][i] = 1, res[1][i] = 1;
            }
            else 
            {
                if(a == 0 && b == 0) 
                {
                    flag = false;
                    break;
                }
                if(a > b)
                {
                    a--;
                    res[0][i] = 1;
                }
                else
                {
                    b--;
                    res[1][i] = 1;
                }
            }
        }
        if(a != 0 || b != 0) flag = false; 

        if(flag) return res;
        else return {};
    }
};
// @lc code=end

