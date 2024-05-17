/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        auto find = [&](vector<int>& t, int a)
        {
            vector<int> cnt(n + 1);
            int s = 0;
            for(int i = 0, j = 0; i < n; i++)
            {
                if(cnt[nums[i]]++ == 0) s++;

                while(s > a)
                {
                    if(--cnt[nums[j++]] == 0) s--;
                }
                t[i] = j;
            }
        };

        vector<int> lower(n), upper(n);
        find(lower, k);
        find(upper, k - 1);
 
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += upper[i] - lower[i];
        }
        
        return res;
    }
};
// @lc code=end

