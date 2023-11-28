/*
 * @lc app=leetcode.cn id=2416 lang=cpp
 *
 * [2416] 字符串的前缀分数和
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 1000010;
    int son[N][26], idx = 0, cnt[N];
    vector<int> res;

    void insert(string s)
    {
        int p = 0;
        for(auto e : s)
        {
            int u = e - 'a';
            if(!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
            cnt[p]++;
        }
    }

    int find(string s)
    {
        int res = 0, p = 0;
        for(auto e : s)
        {
            int u = e - 'a';
            if(!son[p][u]) break;
            else {
                p = son[p][u];
                res += cnt[p];
            }
        }

        return res;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        
        for(auto e : words)
        {
            insert(e);
        }

        for(auto e : words)
        {
            int t = find(e);
            res.push_back(t);
        }

        return res;
    }
};
// @lc code=end

