/*
 * @lc app=leetcode.cn id=2195 lang=cpp
 *
 * [2195] 向数组中追加 K 个整数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0); // 添加哨兵位方便从1开始加
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;

        for(int i = 0; i < n - 1; i++)
        {
            if(k == 0) break;
            if(nums[i + 1] - nums[i] > 1 && k > 0)
            {
                long long c = nums[i + 1] - nums[i] - 1;
                if(k < c)
                    c = k;          
                // 等差公式求和，首项和尾项
                long long x = nums[i] + 1, y = nums[i] + c;      
                res += (long long)c * (x + y) / 2;
                k -= c;
            }
        }

        int idx = 1;
        if(k > 0)
        {
            long long x = nums[n - 1] + 1, y = nums[n - 1] + k;
            res += (long long)k * (x + y) / 2;
        }
        
        return res;
    }
};
// @lc code=end

