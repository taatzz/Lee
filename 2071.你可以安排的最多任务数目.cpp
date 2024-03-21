/*
 * @lc app=leetcode.cn id=2071 lang=cpp
 *
 * [2071] 你可以安排的最多任务数目
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, vector<int>& workers, int k, int t, int num)
    {
        int n = nums.size();
        multiset<int> h;
        for(int i = 0; i < k; i++) 
        {
            h.insert(workers[workers.size() - 1 - i]);
            // cout << workers[workers.size() - 1 - i] << endl;
        }

        for(int i = k - 1; i >= 0; i--)
        {
            int x = nums[i];
            auto it = h.lower_bound(x);
            if(it != h.end()) h.erase(it);
            else if(t > 0)
            {
                auto it2 = h.lower_bound(x - num);
                if(it2 != h.end()) h.erase(it2), t--;
                else return false;
            }
            else return false;
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 0, r = min(tasks.size(), workers.size());

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(tasks, workers, mid, pills, strength))
                l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

