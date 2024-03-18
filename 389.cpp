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
//     bool isSubstringPresent(string s) {
//         int n = s.size();
        
//         unordered_set<string> h;
//         for(int i = 1; i < n; i++)
//         {
//             int j = i - 2 + 1;
//             h.insert(s.substr(j, 2));
//         }
        
//         for(int i = 1; i < s.size(); i++)
//         {
//             int j = i - 2 + 1;
//             string t = s.substr(j, 2);
//             reverse(t.begin(), t.end());
//             if(h.count(t)) return 1;
//         }
        
//         return 0;
//     }
// };

// // T2
// class Solution {
// public:
//     long long countSubstrings(string s, char c) {
//         long long res = 0;
        
//         int prev = 0;
//         for(int i = 0; i < s.size(); i++)
//         {
//             if(s[i] == c)
//             {
//                 prev ++;
//                 res += prev;
//             }
//         }
        
//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     int cnt[26];
//     int minimumDeletions(string s, int k) {
//         int n = s.size();
        
//         for(int i = 0; i < n; i++)
//         {
//             cnt[s[i] - 'a']++;
//         }
//         ranges::sort(cnt);
        
//         int mx = 0;
//         for(int i = 0; i < 26; i++)
//         {
//             int x = cnt[i], sum = 0;
//             for(int j = i; j < 26; j++)
//             {
//                 sum += min(cnt[j], cnt[i] + k);
//             }
//             mx = max(mx, sum);
//         }
        
//         return n - mx;
//     }
// };