/*
 * @lc app=leetcode.cn id=1268 lang=cpp
 *
 * [1268] 搜索推荐系统
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 20010;
    int son[N][26], idx;
    unordered_map<int, vector<int>> h;
    vector<string> word;

    void insert(string& s, int x)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
            h[p].push_back(x);
        }
    }

    vector<string> query(string s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return {};
            p = son[p][u];
        }

        priority_queue<string, vector<string>, greater<string>> q;
        for(auto& e : h[p]) q.push(word[e]);

        vector<string> res;
        int k = 0;
        while(q.size() && k < 3) 
        {
            res.push_back(q.top());
            q.pop();
            k++;
        }

        return res;
    }

    vector<vector<string>> suggestedProducts(vector<string>& words, string s) {
        word = words;
        for(int i = 0; i < word.size(); i++)
        {
            insert(words[i], i);
        }

        vector<vector<string>> res;
        for(int i = 0; i < s.size(); i++)
        {
            res.push_back(query(s.substr(0, i + 1)));
        }

        return res;
    }
};
// @lc code=end

