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

// T1
// class Solution {
// public:
//     vector<vector<int>> modifiedMatrix(vector<vector<int>>& nums) {
//         int m = nums.size(), n = nums[0].size();
//         vector<int> t(n, 0);
        
//         for(int j = 0; j < n; j++)
//         {
//             int mx = 0;
//             for(int i = 0; i < m; i++)
//             {
//                 mx = max(mx, nums[i][j]);
//             }
//             t[j] = mx;
//         }
        
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//                 if(nums[i][j] == -1) nums[i][j] = t[j];
//         }
        
//         return nums;
//     }
// };


// T2
// class Solution {
// public:
//     int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
//         int n = nums.size(), m = pattern.size() + 1;
//         int res = 0;

//         for(int i = m - 1; i < n; i++)
//         {
//             int j = i - m + 1;
//             bool flag = true;
//             for(int k = 0; k < m - 1; k++)
//             {
//                 if(pattern[k] == 1)
//                 {
//                     if(nums[j + k + 1] <= nums[j + k])
//                     {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 else if(pattern[k] == 0)
//                 {
//                     if(nums[j + k + 1] != nums[j + k])
//                     {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 else
//                 {
//                     if(nums[j + k + 1] >= nums[j + k])
//                     {
//                         flag = false;
//                         break;
//                     }
//                 }
//             }
//             if(flag) res++;
//         }

//         return res;
//     }
// };


// T3 贪心 因为可以随意交换所以从小到大开始进行填充，对于奇数大小的数字，只需要考虑偶数个位置，中间的位置不重要
// class Solution {
// public:
//     static bool cmp(string& a, string& b)
//     {
//         return a.size() < b.size();
//     }

//     int maxPalindromesAfterOperations(vector<string>& words) {
//         int n = words.size();

//         unordered_map<char, int> h;
//         for(auto& e : words)
//         {
//             for(auto& t : e)
//             {
//                 h[t] ++;
//             }
//         }

//         sort(words.begin(), words.end(), cmp);
//         int res = 0;
//         for(auto& e : words)
//         {
//             int x = e.size();
//             bool flag = false;
//            // 单个字符直接答案加一
//             if(x == 1) 
//             {
//                 res++;
//                 continue;
//             }
//             if(x % 2 == 1) x--;
//             for(auto& [tmp, cnt] : h)
//             {
//                 if(cnt == 0 || cnt == 1) continue;
//                 if(cnt >= x) 
//                 {
//                     h[tmp] -= x;
//                     x = 0;
//                 }
//                 else
//                 {
//                     if(cnt % 2 == 0) 
//                     {
//                         x -= cnt;
//                         h[tmp] = 0;
//                     }
//                     else 
//                     {
//                         x -= (cnt - 1);
//                         h[tmp] = 1;
//                     }
//                 }
//                 // 偶数个位置可以全部填上
//                 if(x == 0) 
//                 {
//                     flag = true;
//                     break;
//                 }
//             }
//             if(flag) res++;
//         }   

//         return res;
//     }
// };


// T4 字符串哈希
class Solution {
public:
    typedef unsigned long long ULL;
    static const int N = 1000010, P = 131;
    ULL s[N], p[N];

    ULL get(int l, int r)
    {
        return s[r] - s[l - 1] * p[r - l + 1];
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        vector<int> t(n - 1, 0);
        for(int i = 0; i < n - 1; i++)
            if(nums[i] < nums[i + 1]) t[i] = 1;
            else if(nums[i] == nums[i + 1]) t[i] = 0;
            else t[i] = -1;

        p[0] = 1;
        for(int i = 1; i < n; i++)
        {
            s[i] = s[i - 1] * P + t[i - 1];
            p[i] = p[i - 1] * P;
        }


        vector<ULL> tmp(pattern.size() + 1);
        for(int i = 1; i <= pattern.size(); i++) tmp[i] = tmp[i - 1] * P + pattern[i - 1];

        // 窗口长度减一，数组长度减一
        int m = pattern.size(), res = 0;
        for(int i = m; i < n; i++)
        {
            int j = i - m + 1;
            if(get(j, i) == tmp[pattern.size()]) res ++;
        }

        return res;
    }
};