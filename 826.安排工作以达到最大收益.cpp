/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    static int cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> value;

        for(int i = 0; i < difficulty.size(); i++)
        {
            value.push_back( {difficulty[i], profit[i]} );
        }
        sort(value.begin(), value.end());
        sort(worker.begin(), worker.end());

        int i = 0, mx = 0;
        int res = 0;
        for(int j = 0; j < worker.size(); j++)
        {
            // 当前工人可以完成的工作，找到可以完成的工作的最大价值
            while(i < value.size() && value[i].first <= worker[j])
            {
                mx = max(mx, value[i].second);
                i++;
            }
            res += mx;
        }
        return res;
    }
};
// @lc code=end

