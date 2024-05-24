/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), 
        [&](string& a, string& b){ return a.size() < b.size(); });

        auto check = [&](string& a, string& b)
        {
            if(a.size() != b.size() + 1) return false;
            int i = 0, j = 0, cnt = 0;
            while(i < a.size() && j < b.size())
            {
                if(a[i] == b[j])
                {
                    i++, j++;
                }
                else i++, cnt++;
                if(cnt >= 2) return false;
            }

            return true;
        };

        vector<int> f(n);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            f[i] = 1;
            for(int j = i - 1; j >= 0; j--)
            {
                if(check(words[i], words[j])) 
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }

        return res;
    }
};
// @lc code=end

