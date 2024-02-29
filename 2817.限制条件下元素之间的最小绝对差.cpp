/*
 * @lc app=leetcode.cn id=2817 lang=cpp
 *
 * [2817] 限制条件下元素之间的最小绝对差
 */

// @lc code=start
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        map<int, int> h;
        for(auto e : nums) h[e]++;

        int i = 0, k = 0;
        while(k < x)
        {
            h[nums[k]]--;
            if(h[nums[k]] == 0) h.erase(nums[k]);
            k++;
        }

        int res = INT_MAX;
        while(h.size())
        {
            auto t = h.lower_bound(nums[i]);

            if(t == h.end()) 
            {
                res = min(res, abs(nums[i] - (*(h.rbegin())).first));
            }
            else if((*t).first == nums[i]) return 0;
            else
            {
                if(t != h.begin())
                    res = min(res, abs((*prev(t)).first - nums[i]));
                if(t != --h.end())
                    res = min(res, abs((*next(t)).first - nums[i]));
                res = min(res, abs((*t).first - nums[i]));
            }
            i++;
            h[nums[k]]--;
            if(h[nums[k]] == 0)
                h.erase(nums[k]);
            k++;
        }

        return res;
    }
};
// @lc code=end

