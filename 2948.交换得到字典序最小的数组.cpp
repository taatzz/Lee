#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> t;
        for(int i = 0; i < n; i++) t.emplace_back(nums[i], i);
        sort(t.begin(), t.end());

        int i = 0;
        vector<int> res(n);
        while(i < n)
        {
            int start = i;
            i++;
            set<int> h;
            h.insert(t[start].second);
            while(i < n and t[i].first - t[i - 1].first <= k) 
            {
                h.insert(t[i].second);
                i++;
            }

            auto it = h.begin();
            for(; start < i; start++, it++) 
            {
                res[*it] = t[start].first;
            }
        }

        return res;
    }
};