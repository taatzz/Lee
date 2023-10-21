/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 可以哈希表统计较短数组中每个元素出现次数，然后求交集
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;

        int index1 = 0, index2 = 0, size1 = nums1.size(), size2 = nums2.size();

        while(index1 < size1 && index2 < size2)
        {
            if(nums1[index1] == nums2[index2])
            {
                res.push_back(nums1[index1]);
                index1++;
                index2++;
            }
            else if(nums1[index1] < nums2[index2]) index1++;
            else index2++;
        }

        return res;
    }
};
// @lc code=end

