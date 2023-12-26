/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 *
 * [2861] 最大合金数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(int x, vector<vector<int>>& c, vector<int>& s, vector<int>& cost, int k)
    {
        for(int i = 0; i < c.size(); i++)
        {
            long long sum = 0;
            for(int j = 0; j < c[i].size(); j++)
            {
                if(s[j] >= (long long)x * c[i][j]) continue;

                sum += (long long)((long long)x * c[i][j] - s[j]) * cost[j];
            }
            if(sum <= k) return true;
        }

        return false;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& c, vector<int>& s, vector<int>& cost) {
        int l = 0, r = *min_element(s.begin(), s.end()) + budget;

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(mid, c, s, cost, budget)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

