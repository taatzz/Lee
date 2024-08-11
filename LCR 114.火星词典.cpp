#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 10010;
    int h[N], e[N], ne[N], in[N], idx, cnt;
    bool st[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        in[b]++;
    }

    bool build(string& a, string& b)
    {
        int len = min(a.size(), b.size());
        for(int i = 0; i < len; i++)
        {
            int c1 = a[i] - 'a', c2 = b[i] - 'a';
            if(c1 != c2)
            {
                add(c1, c2);
                return true;
            }
        }
        return a.size() <= b.size();
    }

    string alienOrder(vector<string>& words) {
        memset(h, -1, sizeof h);
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            for(char c : words[i])
                if(!st[c - 'a'] && ++cnt >= 0) st[c - 'a'] = true;

            for(int j = 0; j < i; j++)
            {
                if(!build(words[j], words[i])) return "";
            }
        }

        queue<int> q;
        string res;
        for(int i = 0; i < 26; i++)
        {
            if(st[i] && in[i] == 0) q.push(i);
        }

        while(q.size())
        {
            auto t = q.front();
            q.pop();
            res += t + 'a';
            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(--in[j] == 0)
                {
                    q.push(j);
                }
            }
        }

        return res.size() == cnt ? res : "";
    }
};