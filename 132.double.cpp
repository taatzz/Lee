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
//     string clearDigits(string s) {
//         int n = s.size();
//         int pre = 0;

//         vector<bool> st(n);
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] >= '0' && s[i] <= '9')
//             {
//                 st[i] = 1;
//                 for(int j = i - 1; j >= 0; j--)
//                 {
//                     if(!st[j])
//                     {
//                         st[j] = 1;
//                         break;
//                     }
//                 }
//             }
//         }
//         string res;
//         for(int i = 0; i < n; i++)
//             if(!st[i]) res += s[i];

//         return res;
//     }
// };


// class Solution {
// public:
//     int findWinningPlayer(vector<int>& nums, int k) {
//         stack<int> stk;

//         int n = nums.size(), res = 0;
//         vector<int> left(n, -1), right(n, n);
//         for(int i = 0; i < n; i++)
//         {
//             while(stk.size() && nums[stk.top()] <= nums[i])
//             {
//                 right[stk.top()] = i;
//                 stk.pop();
//             }
//             if(stk.size()) left[i] = stk.top();
//             stk.push(i);
//         }

//         int mx = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(i == 0)
//             {
//                 if(right[i] - 1 - i >= k) return i;
//             }
//             int x = left[i] == -1 && i > 0 ? 1 : 0;
//             if(nums[i] > mx) mx = nums[i], res = i;
//             if(x == 0) continue;
//             if(right[i] - 1 - i + x >= k) return i;
            
//         }

//         return res;
//     }
// };


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
        {
            int cnt = 0, pre = nums[i], j;
            for(j = i + 1; cnt <= k && j != i;)
            {
                if(j == n) j = 0;
                if(nums[j] != pre) cnt++;
                pre = nums[j];
                j++;
                if(j == n) j = 0;
            }

            if(j > i) res = max(res, j - i);
            else res = max(res, n - i + j);
        }

        return res;
    }
};