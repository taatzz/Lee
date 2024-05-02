#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int ,int> pii;

    vector<int> minInterval(vector<vector<int>>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        vector<pii> t;
        for(int i = 0; i < queries.size(); i++)
        {
            t.emplace_back(queries[i], i);
        }
        sort(t.begin(), t.end());

        int i = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<int> res(queries.size());
        for(auto& [k, idx] : t)
        {
            while(i < nums.size() && nums[i][0] <= k)
            {
                int l = nums[i][0], r = nums[i][1];
                q.emplace(r - l + 1, r);
                i++;
            }
            while(q.size() && q.top().second < k) q.pop();

            if(q.size())
                res[idx] = q.top().first;
            else res[idx] = -1;
        }

        return res;
    }
};