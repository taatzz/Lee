/*
 * @lc app=leetcode.cn id=2653 lang=cpp
 *
 * [2653] 滑动子数组的美丽值
 */

// @lc code=start
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    int find(map<int, int>& h, int x)
    {
        int cnt = 0;
        for(auto e : h)
        {
            if(e.second)
                cnt += e.second;
            if(cnt >= x) return (e.first < 0 ? e.first : 0);
        }
        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        // 使用map后续查找时必须是有序的
        map<int, int> h;

        for(int i = 0; i < k; i++) h[nums[i]]++;

        vector<int> res;
        res.push_back(find(h, x));

        for(int i = k; i < nums.size(); i++)
        {
            h[nums[i]]++;
            h[nums[i - k]]--;
            res.push_back(find(h, x));
        }
        
        return res;
    }
};
// @lc code=end

