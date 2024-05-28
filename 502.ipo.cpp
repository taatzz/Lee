/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        priority_queue<pii, vector<pii>, less<pii>> t;

        for(int i = 0; i < profits.size(); i++)
        {
            q.push({capital[i], profits[i]});
        }

        int cnt = 0;
        while(q.size() && cnt < k)
        {
            auto tmp = q.top();

            if(w >= tmp.first)
            {
                t.emplace(tmp.second, tmp.first);
                q.pop();
            }
            else
            {
                if(t.size() == 0) break;
                w += t.top().first;
                t.pop();
                cnt++;
            }
        }
        while(cnt < k && t.size()) 
        {
            w += t.top().first;
            t.pop();
            cnt++;
        }

        return w;
    }
};
// @lc code=end

