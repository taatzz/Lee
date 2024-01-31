/*
 * @lc app=leetcode.cn id=1942 lang=cpp
 *
 * [1942] 最小未被占据椅子的编号
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // 到达时间离开时间和到达顺序
        vector<pair<pair<int, int>, int>> t;
        //可以坐的最小椅子
        priority_queue<int, vector<int>, greater<int>> q;
        // 到达人的离开时间和坐的椅子
        priority_queue<PII, vector<PII>, greater<PII>> leave;
        for(int i = 0; i < times.size(); i++) q.push(i);

        for(int i = 0; i < times.size(); i++)
        {
            int a = times[i][0], b = times[i][1];
            t.push_back({{a, b}, i});
        }
        sort(t.begin(), t.end());

        for(int i = 0; i < t.size(); i++)
        {
            int a = t[i].first.first, b = t[i].first.second, c = t[i].second;
            while(leave.size() && leave.top().first <= a)
            {
                q.push(leave.top().second);
                leave.pop();
            }

            if(c == targetFriend) return q.top();
            leave.push({b, q.top()});
            q.pop();
        }

        return 0;
    }
};
// @lc code=end

