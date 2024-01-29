/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int s[N];

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int res = 0;

        vector<int> right(n + 1), left(n);
        for(int i = n - firstLen; i >= 0; i--)
        {
            int j = i + firstLen - 1;
            right[i] = max(right[i + 1], s[j + 1] - s[i]);
        }
        for(int i = secondLen - 1; i < n; i++)
        {
            int j = i - secondLen + 1;
            if(i - 1 >= 0)
                left[i] = max(left[i - 1], s[i + 1] - s[j]);
            else    
                left[i] = max(left[i], s[i + 1] - s[j]);
            for(int j = i + 1; j < n; j++)
                res = max(res, left[i] + right[j]);
        }

        right = vector<int> (n + 1, 0);
        left = vector<int> (n + 1, 0);
        for(int i = n - secondLen; i >= 0; i--)
        {
            int j = i + secondLen - 1;
            right[i] = max(right[i + 1], s[j + 1] - s[i]);
        }
        for(int i = firstLen - 1; i < n; i++)
        {
            int j = i - firstLen + 1;
            if(i - 1 >= 0)
                left[i] = max(left[i - 1], s[i + 1] - s[j]);
            else
                left[i] = s[i + 1] - s[j];
            for(int j = i + 1; j < n; j++)
                res = max(res, left[i] + right[j]);
        }

        return res;
    }
};
// @lc code=end

