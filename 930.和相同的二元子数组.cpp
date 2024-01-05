/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size(), res = 0;
//         int s1 = 0, s2 = 0, l1 = 0, l2 = 0;

//         for(int i = 0; i < n; i++)
//         {
//             s1 += nums[i];
//             s2 += nums[i];

//             while(l1 <= i && s1 > goal) s1 -= nums[l1++];
//             while(l2 <= i && s2 >= goal) s2 -= nums[l2++];

//             res += l2 - l1;
//         }

//         return res;
//     }
// };
// @lc code=end

class Solution{
public:
    int numSubarraysWithSum(vector<int>& nums, int x)
    {
        int n = nums.size();
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        unordered_map<int, int> h;
        h.insert({0, 1}); // 一开始插入一个0，表示从第一个元素开始符合条件的子数组

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int t = s[i + 1] - x;
            if(h.find(t) != h.end()) res += h[t];
            h[s[i + 1]] ++;
        }

        return res;
    }
};