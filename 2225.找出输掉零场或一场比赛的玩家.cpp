/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, int> h;
        for(auto& e : nums)
        {
            h[e[1]]++;
        }

        vector<int> a, b;
        unordered_set<int> st, st1;
        for(int i = 0; i < n; i++)
        {
            if(h.find(nums[i][0]) == h.end() && !st1.count(nums[i][0])) 
            {
                a.push_back(nums[i][0]);
                st1.insert(nums[i][0]);
            }
            if(h[nums[i][1]] == 1 && !st.count(nums[i][1])) 
            {
                b.push_back(nums[i][1]);
                st.insert(nums[i][1]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        return {a, b};
    }
};
// @lc code=end

