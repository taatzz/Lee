/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        priority_queue<pair<double, PII>, vector<pair<double, PII>>, less<pair<double, PII>>> q;

        for(auto& e : classes)
        {
            int a = e[0], b = e[1];
            double dif = (double)(a + 1) / (b + 1) - (double)a / b;
            q.push({dif, {a, b}});
        }

        while(k --)
        {
            auto t = q.top();
            q.pop();
            int a = t.second.first + 1, b = t.second.second + 1;
            double dif = (double)(a + 1) / (b + 1) - (double)a / b;
            q.push({dif, {a, b}});
        }

        double res = 0;
        while(q.size())
        {
            auto t = q.top();
            q.pop();
            int a = t.second.first, b = t.second.second;
            res += (double)a / b;
        }

        return res / classes.size();
    }
};
// @lc code=end

