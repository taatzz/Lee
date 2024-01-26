/*
 * @lc app=leetcode.cn id=2115 lang=cpp
 *
 * [2115] 从给定原材料中找到所有可以做出的菜
 */

// @lc code=start
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> in;

        int n = recipes.size();
        for(int i = 0; i < n; i++)
        {
            for(auto& e : ingredients[i])
            {
                g[e].push_back(recipes[i]);
                in[recipes[i]]++;
            }
        }

        queue<string> q;
        for(auto& e : supplies) q.push(e);

        vector<string> res;
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            for(auto& ne : g[t])
                if(--in[ne] == 0)
                {
                    q.push(ne);
                    res.push_back(ne);
                }
        }

        return res;
    }
};
// @lc code=end

