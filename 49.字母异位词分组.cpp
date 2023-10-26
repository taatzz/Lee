/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 排序后统计相同序列的元字符串
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > hash;

        for(auto e : strs)
        {
            string tmp =  e;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(e);
        }

        vector<vector<string> > res;

        for(auto e : hash)
            res.push_back(e.second);

        return res;
    }
};
// @lc code=end

