/*
 * @lc app=leetcode.cn id=1801 lang=cpp
 *
 * [1801] 积压订单中的订单总数
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII, vector<PII>, greater<PII>> sell;
        priority_queue<PII, vector<PII>, less<PII>> buy;
        int mod = 1e9 + 7;

        for(auto& e : orders)
        {
            int a = e[0], b = e[1], c = e[2];
            if(c == 0)
            {
                int x = 0;
                if(sell.size() && sell.top().first <= a)
                {
                    while(sell.size() && sell.top().first <= a && x < b)
                    {
                        // 可以匹配就去统计匹配的数量
                        // 当前匹配元素的数量大于货物数量，匹配货物减去差值
                        if(x + sell.top().second > b)
                        {
                            auto t = sell.top();
                            sell.pop();
                            t.second -= b - x;
                            x = b;
                            sell.push(t);
                            continue;
                        }
                        else x += sell.top().second;
                        sell.pop();
                    }
                    // 如果当前元素没有完全匹配继续插入
                    if(x < b) buy.push({a, b - x});
                }
                else buy.push({a, b});
            }
            else
            {
                int x = 0;
                if(buy.size() && buy.top().first >= a)
                {
                    while(buy.size() && buy.top().first >= a && x < b)
                    {
                        if(x + buy.top().second > b)
                        {
                            auto t = buy.top();
                            buy.pop();
                            t.second -= b - x;
                            x = b;
                            buy.push(t);
                            continue;
                        }
                        else x += buy.top().second;
                        buy.pop();
                    }
                    if(x < b) sell.push({a, b - x});
                }
                else sell.push({a, b});
            }
        }

        long long res = 0;
        while(sell.size())
        {
            res += sell.top().second;
            sell.pop();
        }
        while(buy.size())
        {
            res += buy.top().second; 
            buy.pop();
        }

        return res % mod;
    }
};
// @lc code=end

