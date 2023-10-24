/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<string, int>& a, const pair<string, int>& b)
    {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string, int> hash;
        vector<pair<string, int> > heap;

        for(auto e : words)
        {
            hash[e] += 1;
        }

        for(auto e : hash)
            heap.push_back(e);
        priority_queue<pair<string, int>, vector<pair<string, int> >, decltype(cmp)> q(heap.begin(), heap.end(), cmp);

        vector<string> res;
        while(--k >= 0)
        {
            res.push_back(q.top().first);
            q.pop();
        }

        return res;
    }
};
// @lc code=end

