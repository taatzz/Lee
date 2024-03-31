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
//     int sumOfTheDigitsOfHarshadNumber(int x) {
//         int n = x, sum = 0;
//         while(n)
//         {
//             sum += n % 10;
//             n /= 10;
//         }      

//         if(x % sum == 0) return 1;
//         else return 0;
//     }
// };

// class Solution {
// public:
//     int maxBottlesDrunk(int num1, int num2) {
//         int res = 0;
//         while(num1 >= num2)
//         {
//             res += num2;
//             num1 -= num2;
//             num2++;
//             num1 += 1;
//         }

//         return res + num1;
//     }
// };

// class Solution {
// public:
//     static const int N = 100010;
//     long long countAlternatingSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         int i = 0;
//         long long res = 0;
//         while(i < n)
//         {
//             if(i + 1 < n && nums[i] != nums[i + 1])
//             {
//                 int start = i;
//                 i++;
//                 while(i + 1 < n && nums[i] != nums[i + 1]) i++;
//                 int len = i - start + 1;
//                 res += (long long)(len + 1) * len / 2;
//                 i++;
//             }
//             else res++, i++;
//         }

//         return res;
//     }
// };

