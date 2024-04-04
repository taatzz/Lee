/*
 * @lc app=leetcode.cn id=2402 lang=cpp
 *
 * [2402] 会议室 III
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<long long, int> pii;
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] <= b[0];
    }

    int mostBooked(int n, vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> room;
        priority_queue<pii, vector<pii>, greater<pii>> time;
        for(int i = 0; i < n; i++) room.push(i);
        vector<int> cnt(n);

        for(int i = 0; i < nums.size(); i++)
        {
            long long st = nums[i][0], end = nums[i][1], id;
            // 当前开始时间是否有会议结束
            while(time.size() && time.top().first <= st)
            {
                room.push(time.top().second);
                time.pop();
            }
            // 如果没有空闲的会议室，就找一个最先结束的会议，当前会议延时到后面
            if(!room.size())
            {
                auto t = time.top();
                time.pop();
                end += t.first - st;
                id = t.second;
            }
            else
            {
                id = room.top();
                room.pop();
            }
            cnt[id]++;
            time.push({end, id});
        }

        int mx = 0, res = 0;
        for(int i = 0; i < n; i++)
        {
            if(cnt[i] > mx) 
            {
                mx = cnt[i];
                res = i;
            }
        }

        return res;
    }
};
// @lc code=end

