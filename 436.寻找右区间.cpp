/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // typedef pair<int, int> pii;
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        vector<int> tmp;
        unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); i++) 
        {
            tmp.push_back(nums[i][0]);
            // 哈希表存每一个区间的下标
            h[nums[i][0]] = i;
        }
        sort(tmp.begin(), tmp.end());

        vector<int> res(nums.size());
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int x = nums[i][1];
            // 找到大于当前区间终点的起点
            int idx = upper_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
            if(idx > 0) 
            {
                // 如果存在和终点相同的起点优先用，否则在idx小于n的情况下说明存在右区间
                if(tmp[idx - 1] >= x) res[i] = h[tmp[idx - 1]];
                else if(idx < tmp.size()) res[i] = h[tmp[idx]];
                else res[i] = -1;
            }
            else res[i] = h[tmp[idx]];
        }

        return res;
    }   
};
// @lc code=end

