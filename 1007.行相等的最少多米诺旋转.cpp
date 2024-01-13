/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 因为一行变成一样的，所以就只选择第一行的就可以
    // 一共四种情况 1:上面都变成上面第一张 2：上面都变成下面第一张
                // 3.下面都变成下面第一张 4：下面都变成上面第一张
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int num1 = tops[0], num2 = bottoms[0];
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

        for(int i = 0; i < n; i++)
        {
            if(cnt1 != INT_MAX && tops[i] != num1)
                cnt1 = (bottoms[i] == num1) ? cnt1 + 1 : INT_MAX;
            if(cnt2 != INT_MAX && bottoms[i] != num2)
                cnt2 = (tops[i] == num2) ? cnt2 + 1 : INT_MAX;
            if(cnt3 != INT_MAX && tops[i] != num2)
                cnt3 = (bottoms[i] == num2) ? cnt3 + 1 : INT_MAX;
            if(cnt4 != INT_MAX && bottoms[i] != num1)
                cnt4 = (tops[i] == num1) ? cnt4 + 1 : INT_MAX;
        }

        int res = min(min(cnt1, cnt2), min(cnt3, cnt4));

        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

