/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 310;
    int p[N];

    int find(int x)
    {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool check(string& a, string& b)
    {
        int n = a.size(), cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] != b[i]) cnt++;
            if(cnt > 2) return false;
        }

        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        for(int i = 1; i < n; i++) p[i] = i;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(check(strs[i], strs[j]))
                {
                    int a = find(i), b = find(j);
                    if(a != b) p[a] = b;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) 
            if(p[i] == i) res++;

        return res;
    }
};
// @lc code=end

