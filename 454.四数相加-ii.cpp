/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<long long, int> h;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {   
                h[nums1[i] + nums2[j]]++;
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x = nums3[i] + nums4[j];
                if(h.count(-x)) res += h[-x];
            }
        }

        return res;
    }
};
// @lc code=end

