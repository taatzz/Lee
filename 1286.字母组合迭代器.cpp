/*
 * @lc app=leetcode.cn id=1286 lang=cpp
 *
 * [1286] 字母组合迭代器
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class CombinationIterator {
public:
    static const int N = 20;
    bool st[N];
    vector<string> res;
    string tmp;
    int t = -1;

    void dfs(string& s, int x, int start, int n)
    {
        if(x >= n)
        {
            res.push_back(tmp);
            return;
        }

        for(int i = start; i < s.size(); i++)
        {
            if(!st[i])
            {
                tmp.push_back(s[i]);
                st[i] = true;
                dfs(s, x + 1, i + 1, n);
                tmp.pop_back();
                st[i] = false;
            }
        }
    }

    CombinationIterator(string s, int n) {
        sort(s.begin(), s.end());
        dfs(s, 0, 0, n);
    }
    
    string next() {
        return res[++t];
    }
    
    bool hasNext() {
        return t != res.size() - 1;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

