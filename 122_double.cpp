#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>

using namespace std;

// T1
// class Solution {
// public:
    
//     int minimumCost(vector<int>& nums) {
//         int n = nums.size();
        
//         int i = 0, j = n - 1, res = 10000;
//         for(; i < n; i++)
//         {
//             j = n - 1;
//             for(; j - i > 1; j--)
//                 res = min(res, nums[0] + nums[i + 1] + nums[j]);
//         }
        
//         return res;
//     }
// };


// T2 分组循环
class Solution {
public:
    int find(int x)
    {
        int cnt = 0;
        while(x)
        {
            cnt++;
            x -= (x & -x);
        }

        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> t = nums;
        sort(t.begin(), t.end());

        int i = 0;
        while(i < n)
        {
            int start = i, k = find(nums[start]);
            i++;
            while(i < n && find(nums[i]) == k) i++;
            sort(nums.begin() + start, nums.begin() + i);
        }

        for(int i = 0; i < n; i++) 
            if(t[i] != nums[i]) return false;

        return true;
    }
};