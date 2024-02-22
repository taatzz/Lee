/*
 * @lc app=leetcode.cn id=2301 lang=cpp
 *
 * [2301] 替换字符后匹配
 */

// @lc code=start
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int k = sub.size();
        int n = s.size();
        unordered_map<char, unordered_multiset<char>> h;
        
        for(auto& e : mappings)
        {
            char a = e[0], b = e[1];
            h[a].insert(b);
        }

        vector<string> tmp;
        for(int i = k - 1; i < n; i++)
        {
            int j = i - k + 1;
            tmp.push_back(s.substr(j, k));
        }

        for(auto& e : tmp)
        {
            bool flag = true;
            for(int i = 0; i < k; i++)
            {
                if(e[i] != sub[i])
                {
                    if(h[sub[i]].find(e[i]) == h[sub[i]].end())
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) return true;
        }

        return false;
    }
};
// @lc code=end

