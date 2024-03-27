/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int p[N];

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& word) {
        unordered_map<string, vector<int>> h;
        int n = word.size();
        for(int i = 0; i < n; i++) p[i] = i;

        // 通过邮箱地址找相同的人
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < word[i].size(); j++)
            {
                h[word[i][j]].push_back(i);
            }
        }

        // 将相同的人合并到一起
        for(auto& [_, e] : h)
        {
            for(int i = 1; i < e.size(); i++)
            {
                int a = e[i - 1], b = e[i];
                a = find(a), b = find(b);
                if(a != b) p[a] = b;
            }
        }

        // set实现联通分量去重
        unordered_map<int, set<string>> s;
        for(int i = 0; i < n; i++)
        {
            int a = find(i);
            for(int j = 0; j < word[i].size(); j++)
            {
                s[a].insert(word[i][j]);
            }
        }

        vector<vector<string>> res;
        for(auto& [k, e] : s)
        {
            vector<string> tmp;
            // 第一个必须是名称，将名称先放进去
            string x = word[k][0];
            e.erase(x);
            tmp.push_back(x);

            for(auto& t : e)
            {
                tmp.push_back(t);
            }
            res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

