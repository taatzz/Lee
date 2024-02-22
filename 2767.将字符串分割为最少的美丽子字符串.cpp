/*
 * @lc app=leetcode.cn id=2767 lang=cpp
 *
 * [2767] 将字符串分割为最少的美丽子字符串
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> h;
    vector<string> path;
    int res = 20;

    int get(string s)
    {
        int res = 0;
        for(int i = s.size() - 1, j = 1; i >= 0; i--)
        {
            if(s[i] == '1') res += j;
            j *= 2;
        }

        return res;
    }

    void dfs(string s, int x)
    {
        int n = s.size();
        if(x >= n) 
        {
            bool flag = true;
            for(auto& e : path)
            {
                int x = get(e);
                if(h.find(x) == h.end() || e[0] == '0')
                {
                    flag = false;
                    break;
                }
            }
            if(flag) res = min(res, (int)path.size());
            return;
        }

        for(int i = x; i < n; i++)
        {
            int len = i - x + 1;
            path.push_back(s.substr(x, len));
            dfs(s, x + len);
            path.pop_back();
        }
    }

    int minimumBeautifulSubstrings(string s) {
        for(int i = 0, j = 1; i <= 11; i++)
        {
            h.insert(j);
            j *= 5;
        }

        dfs(s, 0);

        return res == 20 ? -1 : res;
    }
};
// @lc code=end

