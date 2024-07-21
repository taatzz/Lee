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
//     string losingPlayer(int x, int y) {
//         int a = min(x, y / 4);

//         if(a % 2) return "Alice";
//         else return "Bob";
//     }
// };

// class Solution {
// public:
//     int minimumLength(string s) {
//         unordered_map<char, set<int>> h;
//         int n = s.size();
//         for(int i = 0; i < n; i++)
//         {
//             h[s[i]].insert(i);
//         }

//         int res = n;
//         for(int i = 1; i < n - 1; i++)
//         {
//             if(h[s[i]].size() < 3) continue;
//             auto it = h[s[i]].lower_bound(i);
//             auto t = it;
//             if(it != h[s[i]].begin() && next(t) != h[s[i]].end())
//             {
//                 res -= 2;
//                 t = it;
//                 h[s[i]].erase(prev(t));
//                 t = it;
//                 h[s[i]].erase(next(t));
//             }
//         }

//         return res;
//     }
// };

