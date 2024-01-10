/*
 * @lc app=leetcode.cn id=2007 lang=cpp
 *
 * [2007] 从双倍数组中还原原数组
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 贪心，我们肯定希望更多的匹配所以我们应该从小到大开始进行匹配，这样可以达到更多的匹配数量。
    vector<int> findOriginalArray(vector<int>& nums) {
        // 奇数一定无法匹配，直接返回
        if(nums.size() % 2) return {};
        // 排序从小到大开始匹配
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> res;
        // 哈希表记录数组的元素次数
        unordered_map<int, int> h;
        for(auto e : nums) h[e]++;

        int cnt = 0; // 匹配的对数
        for(int i = 0; i < nums.size(); i++)
        {
            // 哈希表中没有的元素说明已经消耗完了，直接跳过
            if(h.find(nums[i]) == h.end()) continue;
            if(nums[i] == 0) 
            {
                if(h[0] >= 2)
                {
                    cnt++; // 匹配对数 + 1
                    res.push_back(nums[i]);
                    // 消耗一个元素，为0直接删除元素
                    h[0]--;
                    if(h[0] == 0) h.erase(0);
                }
            }
            else
            {
                if(h.find(nums[i] * 2) != h.end())
                {
                    cnt++;
                    h[nums[i] * 2]--;
                    if(h[nums[i] * 2] == 0) h.erase(nums[i] * 2);
                    res.push_back(nums[i]);
                }
            }
            // 使用一个也删除一个
            h[nums[i]]--;
            if(h[nums[i]] == 0) h.erase(nums[i]);
        }

        if(cnt == n / 2) return res;
        else return {};
    }
};
// @lc code=end

