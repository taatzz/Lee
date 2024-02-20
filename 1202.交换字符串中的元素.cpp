/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    bool st[N];
    vector<vector<int>> res;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void bfs(int x)
    {
        queue<int> q;
        q.push(x);
        vector<int> tmp;

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(!st[j])
                {
                    st[j] = 1;
                    tmp.push_back(j);
                    q.push(j);
                }
            }
        }
        res.push_back(tmp);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        memset(h, -1, sizeof h);
        int n = s.size();

        for(auto e : pairs)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        for(int i = 0; i < n; i++)
        {
            if(!st[i] && h[i] != -1) bfs(i);
        }

        for(vector<int> e : res)
        {
            sort(e.begin(), e.end());
            vector<char> t;
            for(int i = 0; i < e.size(); i++) 
            { 
                t.push_back(s[e[i]]);
            }
            sort(t.begin(), t.end());
            for(int i = 0; i < t.size(); i++) 
            {
                s[e[i]] = t[i];
            }
        }

        return s;
    }
};
// @lc code=end

