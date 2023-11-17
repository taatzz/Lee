/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
#include <string>

using namespace std;

class WordDictionary {
public:
    static const int N = 15010;
    int son[N][26], cnt[N], idx;

    WordDictionary() {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 26; j++)
                son[i][j] = 0;
    }
    
    void addWord(string word) {
        int p = 0;
        for(auto e : word)
        {
            int u = e - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    
    bool dfs(string s, int x, int p)
    {
        // 找到字符串尾部，返回尾部的标记，没有标记就说明字典树中没有当前子串
        if(x == s.size())
            return cnt[p];
        if(s[x] == '.')
        {
            // 递归查找跳过当前字符的所有字典树是否有可以匹配的
            for(int i = 0; i < 26; i++) 
                if(son[p][i] && dfs(s, x + 1, son[p][i])) return true;
            return false;
        }
        else
        {
            int u = s[x] - 'a';
            if(!son[p][u]) return false;
            return dfs(s, x + 1, son[p][u]);
        }
    }

    bool search(string word) {
        return dfs(word, 0, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

