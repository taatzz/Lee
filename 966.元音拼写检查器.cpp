/*
 * @lc app=leetcode.cn id=966 lang=cpp
 *
 * [966] 元音拼写检查器
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    unordered_set<char> t{ 'a','e','i','o','u' };

    string get(string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(c >= 'A' && c <= 'Z')
            {
                s[i] = tolower(s[i]);
                c = tolower(c);
            }
            if(t.find(c) != t.end()) s[i] = '*';
        }

        return s;
    }

    vector<string> spellchecker(vector<string>& word, vector<string>& queries) {
        set<string> h;
        map<string, string> h_lowr, h_vow;
        for(auto& e : word)
        {
            h.insert(e);
        }
        for(auto& e : word)
        {
            string s = e;
            transform(s.begin(),s.end(),s.begin(),::tolower);
            h_lowr.insert({s, e});
        }

        for(auto& e : word)
        {
            string s = get(e);
            // cout << s << endl;
            h_vow.insert({s, e});
        }

        int n = queries.size();
        vector<string> res(n);

        for(int i = 0; i < n; i++)
        {
            if(h.find(queries[i]) != h.end()) res[i] = queries[i];
            else
            {
                string s = queries[i];
                transform(s.begin(),s.end(),s.begin(),::tolower);
                if(h_lowr.find(s) != h_lowr.end())
                {
                    res[i] = h_lowr[s];
                }
                else
                {
                    string tmp = get(queries[i]);
                    if(h_vow.find(tmp) != h_vow.end())
                        res[i] = h_vow[tmp];
                }
            }
        }

        return res;
    }
};
// @lc code=end

