/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 *
 * [2085] 统计出现过一次的公共字符串
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countWords(vector<string>& s1, vector<string>& s2) {
        unordered_map<string, int> h1, h2;
        for(auto e : s1) h1[e]++;
        for(auto e : s2) h2[e]++;

        int res = 0;
        for(auto e : h1) 
            if(e.second == 1 && h2[e.first] == 1) res++;
        
        return res;
    }
};
// @lc code=end

