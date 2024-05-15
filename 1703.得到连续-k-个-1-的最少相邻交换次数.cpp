/*
 * @lc app=leetcode.cn id=1703 lang=cpp
 *
 * [1703] 得到连续 K 个 1 的最少相邻交换次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int s[N];

    int minMoves(vector<int>& nums, int k) {
        vector<int> p;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i])
                p.push_back(i - p.size());
        }

        for(int i = 1; i <= p.size(); i++)
        {
            s[i] = s[i - 1] + p[i - 1];
        }
        int m = p.size();

        int res = INT_MAX;
        for(int i = 0; i <= m - k; i++)
        {
            int j = i + k - 1, mid = (i + j) >> 1;
            // 距离和
            int l = p[mid] * (mid - i + 1) - (s[mid + 1] - s[i]);
            int r = (s[j + 1] - s[mid]) - p[mid] * (j - mid + 1);
            res = min(res, l + r);
        }

        return res;
    }
};
// @lc code=end

