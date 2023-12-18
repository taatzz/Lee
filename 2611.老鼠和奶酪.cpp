/*
 * @lc app=leetcode.cn id=2611 lang=cpp
 *
 * [2611] 老鼠和奶酪
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<PII, vector<PII>, less<PII> > q;
        int n = reward1.size(), res = 0;
        for(int i = 0; i < n; i++)
        {
            q.push({reward1[i] - reward2[i], i});
            res += reward2[i];
        }

        while(k --)
        {
            auto t = q.top();
            q.pop();
            res = res - reward2[t.second] + reward1[t.second];
        }

        return res;
    }
};
// @lc code=end

