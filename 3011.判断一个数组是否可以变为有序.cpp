#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> t = nums;
        auto lowbit = [&](int x)
        {
            int cnt = 0;
            while(x)
            {
                x -= x & -x;
                cnt++;
            }
            return cnt;
        };

        int i = 0;
        while(i < n)
        {
            int start = i, x = lowbit(nums[start]);
            i++;
            while(i < n && lowbit(nums[i]) == x) i++;
            sort(t.begin() + start, t.begin() + i);
        }
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != t[i]) return 0;
        }

        return 1;
    }
};