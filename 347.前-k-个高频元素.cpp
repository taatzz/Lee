/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;

        for(auto e : nums)
            hash[e] += 1;

        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&cmp)> q(cmp);
        for(auto e : hash)
        {
            if(q.size() == k)
            {
                if(q.top().second < e.second)
                {
                    q.pop();
                    q.push(e);
                }
            }
            else q.push(e);
        }

        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.top().first);
            q.pop();
        }

        return res;
    }
};
// @lc code=end

