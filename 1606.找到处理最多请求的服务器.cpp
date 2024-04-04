/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */

// @lc code=start
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> ser;
        priority_queue<pii, vector<pii>, greater<pii>> time;
        for(int i = 0; i < k; i++) ser.insert(i);
        vector<int> cnt(k);

        for(int i = 0; i < arrival.size(); i++)
        {
            while(time.size() && time.top().first <= arrival[i])
            {
                ser.insert(time.top().second);
                time.pop();
            }
            if(ser.size() == 0) continue;
            auto p = ser.lower_bound(i % k);
            if(p == ser.end()) p = ser.begin();
            cnt[*p]++;
            time.push({arrival[i] + load[i], *p});
            ser.erase(p);
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            if(cnt[i] == mx) res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

