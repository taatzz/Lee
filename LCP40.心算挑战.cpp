#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxmiumScore(vector<int>& nums, int cnt) {
        sort(nums.begin(), nums.end(), greater<int>());
        int s = accumulate(nums.begin(), nums.begin() + cnt, 0), n = nums.size();
        if(s % 2 == 0) return s;


        auto find = [&](int x)
        {   
            int res = s - x;
            for(int i = cnt; i < n; i++)
            {
                if(nums[i] % 2 != x % 2) return res + nums[i];
            }

            return 0;
        };

        int res = find(nums[cnt - 1]);
        int x = nums[cnt - 1];
        for(int i = cnt - 2; i >= 0; i--)
        {
            if(nums[i] % 2 != x % 2)
            {
                res = max(res, find(nums[i]));
                break;
            }
        }

        return res;
    }
};