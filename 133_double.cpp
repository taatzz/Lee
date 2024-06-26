#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;


// class Solution {
// public:
//     int minimumOperations(vector<int>& nums) {
//         int n = nums.size();

//         int res = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] % 3) res++;
//         }
//         return res;
//     }
// };

// T2
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0, cnt = 0;
        vector<int> s(n + 10);
        int pre = 0;
        for(int i = 0; i < n; i++)
        {
            pre += s[i];
            if(nums[i] == 0 && pre % 2 == 0) 
            {
                res ++;
                if(i + 3 > n) return -1;
                s[i + 3] -= 1;
                pre++;
            }
            if(nums[i] == 1 && pre % 2 == 1) 
            {
                res++;
                if(i + 3 > n) return -1;
                s[i + 3] -= 1;
                pre++;
            }
        }
        

        return res;
    }
};

// T3
// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int n = nums.size(), res = 0;

//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] == 0 && res % 2 == 0) res++;
//             else if(nums[i] == 1 && res % 2 == 1) res++;
//         }

//         return res;
//     }
// };