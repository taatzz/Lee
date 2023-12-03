/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 从开头结尾选不连续的k张最大 ==> 选连续的n - k 张最小 
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), len = n - k;

        int sum = 0, prev = 0;
        for(int i = 0; i < n; i++) sum += cardPoints[i];
        for(int i = 0; i < len; i++) prev += cardPoints[i];

        int cnt = prev;
        for(int i = len; i < n; i++)
        {
            prev += cardPoints[i] - cardPoints[i - len];
            cnt = min(cnt, prev);
        }

        return sum - cnt;
    }
};
// @lc code=end

