/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27];
        // 统计每一个字母的最远的下标
        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }

        vector<int> res;
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']); // 当前区间的字母的最远下标
            if(i == right) // 走到该字母的最远下标
            {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end

