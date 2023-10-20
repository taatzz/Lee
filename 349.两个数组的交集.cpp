/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;

        int size1 = nums1.size(), size2 = nums2.size();
        int index1 = 0, index2 = 0;
        while(index1 < size1 && index2 < size2)
        {
            if(nums1[index1] == nums2[index2])
            {
                if(res.empty() || res.back() != nums1[index1])
                    res.push_back(nums1[index1]);
                index1++;
                index2++;
            }
            else if(nums1[index1] < nums2[index2])
                index1++;
            else
                index2++;
        }

        return res;
    }
};
// @lc code=end

