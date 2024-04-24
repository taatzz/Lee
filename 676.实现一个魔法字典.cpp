/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class MagicDictionary {
public:
    static const int N = 10010;
    int son[N][26], idx = 0, cnt[N];

    MagicDictionary() {

    }

    void insert(string s)
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
    
    void buildDict(vector<string> word) {
        memset(son, 0, sizeof son);
        for(auto& e : word)
        {
            insert(e);
        }
    }

    bool query(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }

        return cnt[p];
    }
    
    bool search(string s) {
        bool flag = false;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(s[i] == j + 'a') continue;
                string t = s;
                t[i] = j + 'a';
                if(query(t)) return 1;
            }
        }

        return flag;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

