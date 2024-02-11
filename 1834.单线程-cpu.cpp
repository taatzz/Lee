/*
 * @lc app=leetcode.cn id=1834 lang=cpp
 *
 * [1834] 单线程 CPU
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    vector<int> getOrder(vector<vector<int>>& nums) {
        vector<pair<int, PII>> t;
        int n = nums.size();
        for(int i = 0; i < n; i++) t.push_back({nums[i][0], {nums[i][1], i}});
        sort(t.begin(), t.end());

        vector<int> res;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        long long time = t[0].first, i = 0;

        // 从最开始的时间插入任务队列
        while(i < n && time >= t[i].first)
        {
            q.push({t[i].second.first, t[i].second.second});
            i++;
        }
        while(q.size())
        {    
            auto tmp = q.top();
            q.pop();
            time += tmp.first;
            res.push_back(tmp.second);

            // 如果队列为空就将时间调到下一个任务时间
            if(i < n && time < t[i].first && q.size() == 0) time = t[i].first;
            // 将时间小于开始时间的任务加入到队列
            while(i < n && time >= t[i].first)
            {
                q.push({t[i].second.first, t[i].second.second});
                i++;
            }
            
        }
        
        return res;
    }
};
// @lc code=end

