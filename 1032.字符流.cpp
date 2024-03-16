/*
 * @lc app=leetcode.cn id=1032 lang=cpp
 *
 * [1032] 字符流
 */

// @lc code=start
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class StreamChecker {
public:
    static const int N = 400010;
    int son[N][26], index = 0;
    int cnt[N];
    string t;

    void insert(string& s)
    {
        int p = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int x = s[i] - 'a';
            // 当前路径不存在就创建
            if(!son[p][x]) 
            {
                son[p][x] = ++index;
            }
            p = son[p][x];
        }
        cnt[p]++;
    }

    bool find()
    {
        int p = 0;
        for(int i = t.size() - 1; i >= 0; i--)
        {
            int u = t[i] - 'a';
            if(cnt[p]) return true;
            if(!son[p][u]) return false;
            p = son[p][u];
        }

        return cnt[p];
    }

    StreamChecker(vector<string>& words) {
        memset(son, 0, sizeof son);
        for(auto& e : words)
        {
            insert(e);
        }
    }
    
    bool query(char letter) {
        t += letter;
        return find();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end

