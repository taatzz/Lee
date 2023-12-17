// class Solution {
// public:
//     int res = 0;
//     void dfs(int x, int n, int limit)
//     {
//         if(x >= 3)
//         {
//             if(n == 0)
//                 res++;
//             return;
//         }

//         for(int i = 0; i <= limit; i++)
//         {
    
//             dfs(x + 1, n - i, limit);
//         }
//     }
//     int distributeCandies(int n, int limit) {
//         dfs(0, n, limit);

//         return res;
//     }
// };

#include <vector>

// class Solution {
// public:
//     int maximumStrongPairXor(vector<int>& nums) {
//         int res = 0, n = nums.size();

//         for(int i = 0; i < n - 1; i++)
//         {
//             for(int j = i + 1; j < n; j++)
//             {
//                 if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
//                     res = max(res, nums[i] ^ nums[j]);
//             }
//         }

//         return res;
//     }
// };

#include <map>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

// class Solution {
// public:
//     vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
//         int n = a.size();
//         vector<string> ans;
//         sort(a.begin(),a.end());
        
        
//         int start = 0x3f3f3f3f, res = 1;
//         for(int i = 0; i < n - 1; i++)
//         {
//             int j = i + 1;
//             for(; j < n; j++)
//             {
//                 if(a[j][0] == a[i][0])
//                 {
//                     int time1 = stoi(a[j][1]), time2 = stoi(a[i][1]);
//                     start = min(start, min(time1, time2));
//                     if(max(time1,time2) < start + 100)
//                         res++;
//                     else
//                     {
//                         start = 0x3f3f3f3f; 
//                         i++;
//                     }
//                 }
//                 else break;
//                 //cout << res << " ";
//                 if(ans.size() == 0 && res == 3 || ans.size() > 0 && res == 3 && ans.back() != a[i][0]) // 跨越时间的不算
//                     ans.push_back(a[i][0]);
//             }
//             start = 0x3f3f3f3f, res = 1;
//             i = j - 1;
//         }

//         return ans;
//     }
// };



// class Solution {
// public:
//     int findMinimumOperations(string s1, string s2, string s3) {
//         int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
//         int maxnum = min(n1, min(n2, n3));

//         int res = 0, i = 0;
//         for(i = 0; i < maxnum; i++)
//         {
//             if(i == 0 && s1[i] != s2[i])
//                 return -1;
//             if(s1[i] == s2[i] == s3[i])
//             {
//                 continue;
//             }
//             else 
//             {
//                 break;
//             }
//         }

//         if(n1 > i) res += n1 - i;
//         if(n2 > i) res += n2 - i;
//         if(n3 > i) res += n3 - i; 

//         return res;
//     }
// };



// class Solution {
// public:
//     vector<int> findPeaks(vector<int>& mountain) {
//         vector<int> res;
//         int n = mountain.size();

//         for(int i = 1; i < n - 1; i ++)
//             if(mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
//                 res.push_back(i);

//         return res;
//     }
// };

// class Solution {
// public:
//     int countTestedDevices(vector<int>& nums) {
//         int n = nums.size(), res = 0, prev = 0;

//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] + prev > 0)
//             {
//                 res++;
//                 prev -= 1;
//             }
//         }

//         return res;
//     }
// };


// class Solution {
// public:
//     typedef long long LL;
//     LL qmi(int a, int b, int p)
//     {
//         LL res = 1;
//         while(b)
//         {
//             if(b & 1) res = res * a % p;
//             b >>= 1;
//             a = (LL)a * a % p;
//         }

//         return res;
//     }

//     vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {

//         vector<int> res;
//         int i = 0;
//         for(auto e : variables)
//         {
//             int a = e[0], b = e[1], c = e[2], m = e[3];
//             LL t = qmi(a, b, 10);
//             if(qmi(t, c, m) == target) res.push_back(i);
//             i++
//         }

//         return res;
//     }
// };


// class Solution {
// public:
//     static const int N = 1000010;
//     int a[N];

//     long long countSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long res = 0;
//         int maxnum = 0;

//         int i = 0, j = 0;
//         for(; i < n; i++)
//         {
//             a[nums[i]]++;
//             maxnum = max(maxnum, nums[i]);
//             while(i < j && a[maxnum] >= k)
//             {
//                 a[nums[j++]]--;
//                 res += n - i;
//             }
//         }

//         return res;
//     }
// };


// class Solution {
// public:
//     static const int N = 2510;
//     int cnt[N];

//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();

//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 cnt[grid[i][j]] ++;
//             }
//         }

//         vector<int> res(2);
//         for(int i = 1; i <= n * n; i++)
//         {
//             if(cnt[i] > 1) res[0] = i;
//             else if (cnt[i] < 1) res[1] = i;
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         vector<vector<int>> res;
//         for(int i = 2; i < n; i+= 3)
//         {
//             int j = i - 3 + 1;
//             if(nums[j + 1] - nums[j] <= k && nums[i] - nums[j] <= k && nums[i] - nums[j + 1] <= k)
//             {
//                 vector<int> tmp(3);
//                 tmp[0] = nums[j], tmp[1] = nums[j + 1], tmp[2] = nums[i];
//                 res.push_back(tmp);
//             }
//         }
        // if(res.size() * 3 < n)
        // {
        //     res.clear();
        //     return res;
        // }

//         return res;
//     }
// };
