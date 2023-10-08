/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
#include <stack>
#include <iostream>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        index = -1;
        s.push({-1, INT_MAX});
    }
    
    int next(int price) {
        index++;
        while(!s.empty() && s.top().second < price)
        {
            s.pop();
        }

        int res =  index - s.top().first;
        s.push({index, price});
        return res;
    }
private:
    stack<pair<int, int> > s;
    int index;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

