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
//     bool isValid(string s) {
//         int n = s.size();
//         if(n < 3) return 0;
//         unordered_set<char> h = { 'a','e','i','o','u', 'A','E','I','O','U'};
        
//         int a = 0, b = 0, c = 0, d = 0, e = 0;
//         bool flag = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int u = s[i] - 'A', v = s[i] - 'a';
//             int z = s[i] - '0';
//             // cout << u << ' ' << v << " " << z << endl;
            
//             if(s[i] == '@' || s[i] ==  '#' || s[i] == '$') return 0;
//             if(z >= 0 && z <= 9) 
//             {
//                 flag = 1;
//                 continue;
//             }
//             else if(u >= 0 && u <= 25) flag = 1;
//             else if(v >= 0 && v <= 25) flag = 1;
            
//             if(h.count(s[i])) d++; 
//             if(!h.count(s[i])) e++;
//         } 
//         cout << e << endl;
        

//         return (flag ) && d && e;
//     }
// };


// class Solution {
// public:
//     int minimumOperationsToMakeKPeriodic(string s, int k) {
//         int n = s.size();
//         int x = n / k;

//         unordered_map<string, int> h;
//         for(int i = 0; i < n; i += k)
//         {
//             h[s.substr(i, k)]++;
//         }

//         int res = INT_MAX;
//         for(auto& [k, e] : h)
//         {
//             res = min(res, x - e);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     int minAnagramLength(string s) {
//         int n = s.size();

//         vector<int> t(30);
//         for(int i = 0; i < s.size(); i++)
//         {
//             t[s[i] - 'a']++;
//             bool flag = 1;
//             if(n % (i + 1) == 0)
//             {
//                 int j = i + 1, r = j + i + 1;
//                 while(j < r && r <= n)
//                 {
//                     vector<int> cnt(30);
//                     for(j; j < r; j++) cnt[s[j] - 'a']++;
//                     for(int k = 0; k < 26; k++)
//                         if(t[k] != 0 && cnt[k] != t[k]) 
//                         {
//                             flag = 0;
//                             break;
//                         }
//                     if(!flag) break;
//                     r = j + i + 1;
//                 }
//                 if(flag) return i + 1;
//             } 
//         }

//         return n;
//     }
// };
