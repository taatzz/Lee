/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int sum[N];

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> t;

        int n = s.size(), m = queries.size();
        for(int i = 1; i <= n; i++)
        {
            if(s[i - 1] == '|') t.push_back(i - 1);
            sum[i] = sum[i - 1] + (s[i - 1] == '|' ? 0 : 1);
        }

        vector<int> res;

        for(auto& e : queries)
        {
            int a = e[0], b = e[1];
            int left = lower_bound(t.begin(), t.end(), a) - t.begin();
            int right = upper_bound(t.begin(), t.end(), b) - t.begin() - 1;
            if(left >= right) 
            {
                res.push_back(0);
                continue;
            }

            res.push_back(sum[t[right] + 1] - sum[t[left]]);
        }

        return res;
    }
};
// @lc code=end

