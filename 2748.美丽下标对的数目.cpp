/*
 * @lc app=leetcode.cn id=2748 lang=cpp
 *
 * [2748] 美丽下标对的数目
 */

// @lc code=start
#include <vector>
#include <numeric>
// #include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++)
        {
            int t = nums[i];
            while(t >= 10) t /= 10;
            for(int j = i + 1; j < n; j++)
            {    
                if(gcd(t, nums[j] % 10) == 1) 
                {
                    res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

