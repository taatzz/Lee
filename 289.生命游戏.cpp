/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
    int dy[8] = { 0,1,0,-1,1,-1,1,-1 };

    // 一个比特位代表原来的状态，第二个比特位代表后来的状态
    void gameOfLife(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int sum = 0;
                for(int k = 0; k < 8; k++)
                {
                    int a = i + dx[k], b = j + dy[k];
                    if(a >= 0 && a < m && b >= 0 && b < n)
                        sum += (nums[a][b] & 1); // 只统计第一个比特位的信息
                }
                if(nums[i][j] == 1)
                {
                    if(sum == 2 || sum == 3)
                        nums[i][j] |= 2;
                }
                else
                {
                    if(sum == 3)
                    {
                        nums[i][j] |= 2;
                    }
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                nums[i][j] >>= 1;
        }
    }
};
// @lc code=end

