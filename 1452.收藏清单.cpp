/*
 * @lc app=leetcode.cn id=1452 lang=cpp
 *
 * [1452] 收藏清单
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& s) {
        unordered_set<string> h[105]; // 数组比较快
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < s[i].size(); j++)
            {
                h[i].insert(s[i][j]);
            }
        }


        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            bool flag = true;
            for(int j = 0; j < n; j++)
            {
                if(j == i) continue;
                if(h[j].size() < s[i].size()) continue;

                int cnt = 0;
                for(int k = 0; k < s[i].size(); k++)
                    if(h[j].count(s[i][k])) cnt++;

                if(cnt == s[i].size()) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

