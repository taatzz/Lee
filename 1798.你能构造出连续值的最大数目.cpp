/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int res = 0;

        for(int i = 0; i < coins.size(); i++)
        {
            if(coins[i] > res + 1) break;
            res += coins[i];
        }

        return res + 1;
    }
};
// @lc code=end

