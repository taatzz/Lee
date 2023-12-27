/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1 = 0, sum2 = 0;
        int k1 = 1, k2 = 1;

        for(int i = 0; i < player1.size(); i++)
        {
            if((i > 0 && player1[i - 1] == 10 || (i > 1 && player1[i - 2] == 10)))
                sum1 += 2 * player1[i];
            else sum1 += player1[i];
            if((i > 0 && player2[i - 1] == 10 || (i > 1 && player2[i - 2] == 10)))
                sum2 += 2 * player2[i];
            else sum2 += player2[i];
        }
        if(sum1 == sum2) return 0;

        return sum1 > sum2 ? 1 : 2;
    }
};
// @lc code=end

