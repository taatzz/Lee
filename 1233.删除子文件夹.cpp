/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 200010;
    int idx, cnt[N];
    unordered_map<string, int> son[N];

    static bool cmp(string& a, string& b)
    {
        return a.size() < b.size();
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '/')
            {
                int start = i;
                i++;
                string t;
                while(i < s.size() && s[i] != '/') t += s[i], i++;
                if(!son[p].count(t)) son[p][t] = ++idx;
                p = son[p][t];
                i--;
            }
        }
        cnt[p]++;
    }

    bool query(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '/')
            {
                int start = i;
                i++;
                string t;
                while(i < s.size() && s[i] != '/') t += s[i], i++;
                if(!son[p].count(t)) return false;
                p = son[p][t];
                if(cnt[p]) return true;
                i--;
            }
        }

        return false;
    }

    vector<string> removeSubfolders(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        vector<string> res;
        for(auto& e : words)
        {
            if(!query(e)) res.push_back(e);
            insert(e);
        }

        return res;
    }
};
// @lc code=end

