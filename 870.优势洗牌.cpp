/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    // 田忌赛马
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        priority_queue<PII, vector<PII>, less<PII>> q;
        for(int i = 0; i < n; i++) q.push({nums2[i], i});
    
        int i = 0, j = n - 1;
        vector<int> res(n);
        while(q.size())
        {
            auto t = q.top();
            q.pop();
            if(nums1[j] > t.first)
            {
                res[t.second] = nums1[j--];
            }
            else
            {
                res[t.second] = nums1[i++];
            }
        }

        return res;
    }
};
// @lc code=end

