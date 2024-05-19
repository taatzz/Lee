/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int pre = arr[0], win = 0;
        for(int i = 1; i < arr.size() && win < k; i++)
        {
            if(arr[i] > pre)
            {
                pre = arr[i];
                win = 0;
            }
            win++;
        }

        return pre;
    }
};
// @lc code=end

