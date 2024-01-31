/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 *
 * [2080] 区间内查询数字的频率
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> h;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++)
        {
            h[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto& nums = h[value];
        if(nums.size() == 0) return 0;

        int l = lower_bound(nums.begin(), nums.end(), left) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), right) - nums.begin();

        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

