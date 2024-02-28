/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // 存储以第i个位置为起点可以到达的最远位置
        vector<int> right_most(n + 1, 0);
        int m = ranges.size();
        for(int i = 0; i < m; i++)
        {
            int left = max(0, i - ranges[i]), right = min(n, ranges[i] + i);
            right_most[left] = max(right_most[left], right);
        }

        int cur = 0, res = 0, next = 0;
        for(int i = 0; i < n; i++)
        {
            next = max(next, right_most[i]);
            if(i == cur)
            {
                if(i == next) return -1;
                cur = next;
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

