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


class Solution {
public:
    static const int N = 1010;
    int p[N];
    
    int count(int x)
    {
        int cnt = 0;
        for(int i = 0; i <= 8; i++)
        {
            if((x & (1 << i)) == (1 << i))
                cnt++;
        }
        
        return cnt;
    }
    
    bool canSortArray(vector<int>& nums) {
        vector<int> t = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++) 
        {
            int a = count(nums[i]), b = count(nums[i + 1]);
            if(a == b)
                p[i] = p[i + 1] = 1;
        }
        
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] == t[i]) continue;
            int a = count(nums[i]), b = count(t[i]);
            if(a != b || p[i] != 1) return false;
        }
        
        return true;
    }
};