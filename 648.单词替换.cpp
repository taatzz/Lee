/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int son[N][26], idx, cnt[N];

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }


    string query(string s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) break;
            p = son[p][u];  
            if(cnt[p]) return s.substr(0, i + 1);
        }

        return s;
    }

    string replaceWords(vector<string>& word, string s) {
        for(auto& e : word)
        {
            insert(e);
        }

        int i = 0;
        string res;
        while(i < s.size())
        {
            int start = i;
            i++;
            while(i < s.size() && s[i] != ' ') i++;
            res += query(s.substr(start, i - start));
            res += ' ';
            i++;
        }
        res.pop_back();

        return res;
    }
};
// @lc code=end

