#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> t = nums;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        int n = t.size();
        vector<int> tr1(n + 1), tr2(n + 1);
        auto insert = [](vector<int>& tr, int x, int c)
        {
            for(; x < tr.size(); x += x & -x)
                tr[x] += c;
        };
        auto query = [](vector<int>& tr, int x)
        {
            int res = 0;
            for(; x; x -= x & -x)
                res += tr[x];

            return res;
        };

        vector<int> a, b;
        a.push_back(nums[0]), b.push_back(nums[1]);
        int idx1 = lower_bound(t.begin(), t.end(), nums[0]) - t.begin() + 1;
        int idx2 = lower_bound(t.begin(), t.end(), nums[1]) - t.begin() + 1;
        insert(tr1, idx1, 1), insert(tr2, idx2, 1);
        
        for(int i = 2; i < nums.size(); i++)
        {
            int idx = lower_bound(t.begin(), t.end(), nums[i]) - t.begin() + 1;
            int l = query(tr1, n) - query(tr1, idx);
            int r = query(tr2, n) - query(tr2, idx);
            
            if(l > r) a.push_back(nums[i]), insert(tr1, idx, 1);
            else if(l < r) b.push_back(nums[i]), insert(tr2, idx, 1);
            else
            {
                if(a.size() > b.size()) b.push_back(nums[i]), insert(tr2, idx, 1);
                else a.push_back(nums[i]), insert(tr1, idx, 1);
            }
        }

        vector<int> res;
        for(int e : a) res.push_back(e);
        for(int e : b) res.push_back(e);

        return res;
    }
};