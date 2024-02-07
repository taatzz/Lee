/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 *
 * [2462] 雇佣 K 位工人的总代价
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    long long totalCost(vector<int>& nums, int k, int m) {
        int n = nums.size();
        priority_queue<PII, vector<PII>, greater<PII>> q;
        int i = 0, j = n - 1;
        while(i < m && j >= n - m && i <= j)
        {
            if(i <= j)
            {
                q.push({nums[i], i});
                i++;
            }
            if(i <= j)
            {
                q.push({nums[j], j});
                j--;
            }
        }

        long long res = 0;
        while(k)
        {
            auto t = q.top();
            res += t.first;
            q.pop();
            if(i <= j && t.second <= i)
            {
                q.push({nums[i], i});
                i++;
            }
            else if(i <= j && t.second >= j)
            {
                q.push({nums[j], j});
                j--;
            }
            k--;
        }

        return res;
    }
};
// @lc code=end

