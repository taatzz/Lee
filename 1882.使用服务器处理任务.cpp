/*
 * @lc app=leetcode.cn id=1882 lang=cpp
 *
 * [1882] 使用服务器处理任务
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    typedef long long LL;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<PII, vector<PII>, greater<PII>> s;
        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> time;
        queue<int> q;
        for(int i = 0; i < servers.size(); i++)
        {
            s.push({servers[i], i});
        }

        vector<int> res;
        LL num = 0; // 时间
        auto release = [&]()
        {
            while(time.size() && time.top().first <= num)
            {
                auto t = time.top();
                time.pop();
                s.push({servers[t.second], t.second});
            }
        };

        for(int i = 0; i < tasks.size() || q.size(); i++)
        {
            // 更新时间
            num = max(num, (long long)i);
            release();
            if(!s.size())
            {
                // 没有服务器就把时间更新到最先完成得服务器去
                num = time.top().first;
                release();
            }
            auto t = s.top();
            res.push_back(t.second);
            time.push({tasks[i] + num, t.second});
            s.pop();
        } 

        return res;
    }
};
// @lc code=end

