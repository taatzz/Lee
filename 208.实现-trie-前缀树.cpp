/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <string>

using namespace std;

class Trie {
public:
    static const int N = 100010;
    int son[N][26], idx = 0;
    int cnt[N];
    Trie() {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 26; i++)
                son[i][j] = 0;
    }
    
    void insert(string word) {
        int p = 0;
        for(auto e : word)
        {
            int u = e - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p] ++;
    }
    
    bool search(string word) {
        int p = 0;
        for(auto e : word)
        {
            int u = e - 'a';
            if(!son[p][u]) return false;
            else p = son[p][u];
        }
        if(!cnt[p]) return false;

        return true;
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for(auto e : prefix)
        {
            int u = e - 'a';
            if(!son[p][u]) return false;
            else p = son[p][u];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

