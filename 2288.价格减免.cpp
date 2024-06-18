/*
 * @lc app=leetcode.cn id=2288 lang=cpp
 *
 * [2288] 价格减免
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string discountPrices(string s, int k) {
        int n = s.size(), i = 0;

        auto check = [&](int l, int r)
        {
            if(s[l] != '$' || r - l == 1) return false;
            for(int i = l + 1; i < r; i++)
                if(!isdigit(s[i])) return false;
            return true;
        };

        string res;
        while(i < n)
        {
            int start = i;
            i++;
            while(i < n && s[i] != ' ') i++;

            if(check(start, i))
            {
                char buff[20];
                long long t = stoll(s.substr(start + 1, i - start - 1)) * (100 - k);
                sprintf(buff, "$%lld.%02lld", t / 100, t % 100);
                res += buff;
            }
            else res += s.substr(start, i - start);
            res += ' ';
            i++;
        }
        res.pop_back();

        return res;
    }
};
// @lc code=end

