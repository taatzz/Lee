/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 *
 * [2537] 统计好子数组的数目
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        unordered_map<int, int> h;
        
        int cnt = 1, sum = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            h[nums[i]]++;

            if(h[nums[i]] > 1) 
            {
                cnt++;
                sum += h[nums[i]] - 1;
            }

            while(sum >= k)
            {
                res += n - i;
                h[nums[j]] --;

                if(h[nums[j]] >= 1) 
                {
                    int t = h[nums[j]];
                    sum -= t;
                }
                j++;
            }
        }

        return res;
    }
};
// @lc code=end

