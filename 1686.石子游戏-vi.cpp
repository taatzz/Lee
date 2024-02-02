/*
 * @lc app=leetcode.cn id=1686 lang=cpp
 *
 * [1686] 石子游戏 VI
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n = bob.size();
        priority_queue<PII, vector<PII>, less<PII>> a;

        for(int i = 0; i < n; i++)
        {
            a.push({alice[i] + bob[i], i});
        }
        int sum_a = 0, sum_b = 0, i = 0;
        while(a.size())
        {
            auto t = a.top();
            a.pop();
            if(i++ % 2 == 0) sum_a += alice[t.second];
            else sum_b += bob[t.second];
        }

        if(sum_a > sum_b) return 1;
        else if(sum_a < sum_b) return -1;
        else return 0;
    }
};
// @lc code=end

