/*
 * @lc app=leetcode.cn id=2261 lang=cpp
 *
 * [2261] 含最多 K 个可整除元素的子数组
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> h;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            string s;
            for(int j = i; j < n; j++)
            {
                if(nums[j] % p == 0)
                {
                    cnt++;
                }
                if(cnt > k) break;

                s += to_string(nums[j]);
                s.push_back('#');
                
                h.insert(s);
            }
        }

        return h.size();
    }
};
// @lc code=end

