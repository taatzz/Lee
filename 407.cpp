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
#include <climits>

using namespace std;

// class Solution {
// public:
//     int minChanges(int n, int k) {
//         int res = 0;
//         for(int i = 31; i >= 0; i--)
//         {
//             int a = n >> i & 1, b = k >> i & 1;
//             if(a != b)
//             {
//                 if(a == 0) return -1;
//                 else res++;
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     bool doesAliceWin(string s) {
//         int n = s.size();
//         unordered_set<char> h = { 'a', 'e', 'i', 'o', 'u' };
//         int i = 0, cnta = 0, cntb = 0, com = 0;
//         while(i < n)
//         {
//             if(h.count(s[i]))
//             {
//                 int start = i;
//                 i++;
//                 while(i < n && h.count(s[i])) i++;
//                 int len = i - start;
//                 if(len % 2 == 0) cntb++;
//                 else
//                 {
//                     if(len > 1) com++;
//                     else cnta++;
//                 }
//             }
//             else i++;
//         }
//         if(cnta + cntb + com == 0) return false;

//         if(cnta + com / 2 + cntb >= cntb / 2 + com / 2) return true;
//         else return false;
//     }
// };


// class Solution {
// public:
//     int maxOperations(string s) {
//         int n = s.size(), res = 0;
//         int i = 0, cnt = 0;
//         while(i < n)
//         {
//             if(s[i] == '1')
//             {
//                 cnt++;
//                 int start = i;
//                 i++;
//                 while(i < n && s[i] == '0') i++;
//                 if(i - start > 1)
//                 {
//                     res += cnt;
//                 }
//             }
//             else i++;
//         }

//         return res;
//     }
// };