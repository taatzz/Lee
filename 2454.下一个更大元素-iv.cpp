/*
 * @lc app=leetcode.cn id=2454 lang=cpp
 *
 * [2454] 下一个更大元素 IV
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        vector<int> s, t;

        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            while(!t.empty() && nums[t.back()] < nums[i]) 
            {
                res[t.back()] = x;
                t.pop_back();
            }
            int j = s.size();
            while(j && nums[s[j - 1]] < x) j--;

            t.insert(t.end(), s.begin() + j, s.end());
            s.resize(j);
            s.push_back(i);
        }

        return res;
    }
};
// @lc code=end

