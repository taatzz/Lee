/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<int> d_s(n);
        for(int i = 0; i < n; i++)
            d_s[i] = ((dist[i] + speed[i] - 1) / speed[i]);
        
        sort(d_s.begin(), d_s.end());

        int res = 1;
        for(int i = 1; i < n; i++)
        {
            if(d_s[i] > i) res++;
            else break;
        }

        return res;
    }
};
// @lc code=end

