/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 *
 * [2589] 完成所有任务的最少时间
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 2010;

    int findMinimumTime(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), 
        [&](const vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        vector<int> tr(N);
        auto lowbit = [&](int x)
        {
            return x & -x;
        };

        auto insert = [&](int x, int c)
        {
            for(int i = x; i < tr.size(); i += lowbit(i)) 
                tr[i] += c;
        };
        auto query = [&](int x)->int
        {
            int res = 0;
            for(int i = x; i; i -= lowbit(i))
                res += tr[i];

            return res;
        };

        vector<bool> st(N);
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int start = nums[i][0], end = nums[i][1], k = nums[i][2];
            k -= query(end) - query(start - 1);
            for(int j = end; j >= start && k > 0; j--)
            {
                if(!st[j])
                {
                    res++;
                    k--;
                    st[j] = true;
                    insert(j, 1);
                }
            }
        }

        return res;
    }
};
// @lc code=end

