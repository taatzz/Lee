/*
 * @lc app=leetcode.cn id=1061 lang=cpp
 *
 * [1061] 按字典序排列最小的等效字符串
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 30;
    int p[N];

    int find(int x)
    {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    string smallestEquivalentString(string s1, string s2, string s) {
        int n = s1.size();
        for(int i = 0; i <= 26; i++) p[i] = i;

        for(int i = 0; i < n; i++)
        {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            a = find(a), b = find(b);
            if(a != b) p[a] = b;
        }

        unordered_map<int, char> h;
        for(int i = 0; i < n; i++)
        {
            int a = find(s1[i] - 'a'), b = find(s2[i] - 'a');
            if(!h.count(a)) h[a] = s1[i];
            else h[a] = min(h[a], s1[i]);
            if(!h.count(b)) h[b] = s2[i];
            else h[b] = min(h[b], s2[i]);
        }

        string res;
        for(int i = 0; i < s.size(); i++)
        {
            int a = find(s[i] - 'a');
            if(!h.count(a)) res += s[i];
            else res += h[a];
        }

        return res;
    }
};
// @lc code=end

