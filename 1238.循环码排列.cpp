/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    bool st[N];
    vector<int> t;

    void dfs(int n, int& k, bool& flag)
    {
        if(t.size() == (1 << n))
        {
            flag = true;
        }

        for(int i = 0; i < n; i++)
        {
            int x = k ^ (1 << i);
            if(!st[x])
            {
                st[x] = 1;
                t.push_back(x);
                dfs(n, x, flag);
                if(flag) return;
                t.pop_back();
                st[x] = 0;
            }
        }
    }

    vector<int> circularPermutation(int n, int start) {
        int k = 0;
        if(start <= (1 << n) - 1) k = 0;
        else k = 1;
        t.push_back(start);
        st[start] = 1;
        bool flag = 0;
        dfs(n, start, flag);

        return t;
    }
};
// @lc code=end

