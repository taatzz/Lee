/*
 * @lc app=leetcode.cn id=1383 lang=cpp
 *
 * [1383] 最大的团队表现值
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    static const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> t;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < n; i++)
        {
            t.push_back({efficiency[i], speed[i]});
        }
        sort(t.begin(), t.end(), greater<pii>());
        long long sum = 0, res = 0;
        
        for(int i = 0; i < n; i++)
        {
            long long mn = t[i].first;
            sum += t[i].second;
            res = max(res, (long long) sum * mn);
            q.push(t[i].second);
            if(q.size() == k)
            {
                sum -= q.top();
                q.pop();
            }
        }

        return res % mod;
    }
};
// @lc code=end

