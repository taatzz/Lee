/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int x, int k, int m)
    {
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= x)
            {
                int j = i;
                while(j < nums.size() && nums[j] <= x) 
                {
                    if(j - i == k) break; // 找到相邻的k株花直接break
                    j ++;
                }

                if(j - i >= k) res++; // 统计当前天数可以采到多少花

                j = i - 1; // 从上一次的末尾重新开始
            }
        }

        return res >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // 数组长度小于需要的花数量直接返回-1
        if(bloomDay.size() < (long long)m * k) return -1;

        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(bloomDay, mid, k, m)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

