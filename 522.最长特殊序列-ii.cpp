/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();

        auto check = [&](string a, string b)
        {
            if(a.size() > b.size()) return false;

            int i = 0, j = 0;
            while(j < b.size())
            {
                if(a[i] == b[j]) i++;
                j++;
            }
            return i == a.size();
        };

        int res;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(!check(strs[i], strs[j])) cnt++;
            }
            if(cnt == n - 1)
            {
                res = max(res, (int)strs[i].size());
            }
        }

        return res;
    }
};
// @lc code=end

