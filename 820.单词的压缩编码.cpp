/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 20010;
    int tree[N][26], idx;
    int st[N], len[N];

    bool insert(string s)
    {
        bool flag = false;;
        int n = s.size();
        int p = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int u = s[i] - 'a';
            if(!tree[p][u]) 
            {
                tree[p][u] = ++idx;
            }
            st[p]++;
            p = tree[p][u];
        }
        len[p] = n;

        return flag;
    }

    int minimumLengthEncoding(vector<string>& words) {
        for(int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }

        int res = 0;
        for(int i = 0; i <= idx; i++)
        {
            if(st[i]) continue;
            res += len[i] + 1;
        }

        return res;
    }
}; 
// @lc code=end

