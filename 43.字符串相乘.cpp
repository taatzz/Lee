
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string s1, string s2) {
        auto check = [&]()->bool
        {
            if(s1.size() < s2.size()) return true;
            else if(s1.size() == s2.size())
            {
                int n = s1.size();
                for(int i = 0; i < n; i++)
                {
                    if(s1[i] < s2[i]) return true;
                }
            }

            return false;
        };

        if(check()) swap(s1, s2);

        int n = s1.size(), m = s2.size();

        vector<int> res(m * n + 2);
        int t = 0;
        for(int j = m - 1; j >= 0; j--)
        {
            int idx = t, a = s2[j] - '0';
            for(int i = n - 1; i >= 0; i--)
            {
                int b = s1[i] - '0';
                res[idx] += a * b;
                if(res[idx] >= 10) 
                {
                    res[idx + 1] += res[idx] / 10;
                    res[idx] %= 10;
                }
                idx++;
            }
            t++;
        }

        string ans;
        for(int i = 0; i < res.size(); i++)
        {
            ans += to_string(res[i]);
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end

