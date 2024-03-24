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
//     int maximumLengthSubstring(string s) {
//         int n = s.size();
//         vector<int> cnt(26);

//         int res = 0;
//         for(int i = 0, j = 0; i < n; i++)
//         {
//             int u = s[i] - 'a';
//             cnt[u]++;
//             while(j <= i && cnt[u] > 2) cnt[s[j++] - 'a']--;
//             res = max(res, i - j + 1);
//         }

//         return res;
//     }
// };

// T2
// class Solution {
// public:
//     int minOperations(int k) {
//         if(k == 1) return 0;
        
//         int t = 0, res = 1e6, n = 1;
//         while(n <= k)
//         {
//             int x = n - 1;
//             if(n == k) res = min(res, x);
//             else res = min(res, x + (k + n - 1) / n - 1);
//             n++;
//         }
        
//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
//         int n = nums.size();
//         map<int, long long> h;
//         multiset<long long> f;

//         vector<long long> res;
//         for(int i = 0; i < n; i++)
//         {
//             long long x = 0;
//             if(h.find(nums[i]) != h.end())
//             {
//                 x = h[nums[i]];
//                 h.erase(nums[i]);
//                 auto it = f.lower_bound(x);
//                 f.erase(it);
//             }

//             x += freq[i];
//             f.insert(x);
//             h[nums[i]] = x;
//             res.push_back(*f.rbegin());
//         }

//         return res;
//     }
// };

// T4
class Solution {
public:
    static const int N = 500010;
    int n, index = 0, son[N][26];
    unordered_map<int, int> h;

    vector<int> stringIndices(vector<string>& word, vector<string>& wordsQuery) {
        int t = 0;
        for(auto& s : word)
        {
            int p = 0;
            for(int i = s.size() - 1; i >= 0; i--)
            {
                int x = s[i] - 'a';
                // 当前路径不存在就创建
                if(!son[p][x]) son[p][x] = ++index;
                if(!h.count(p)) h[p] = t;
                else if(word[h[p]].size() > s.size()) h[p] = t;
                p = son[p][x];
            }
            if(h.find(p) == h.end()) h[p] = t;
            else if(word[h[p]].size() > s.size()) h[p] = t;
            t++;
        }
        
        vector<int> res;
        for(auto& s : wordsQuery)
        {
            int p = 0;
            for(int i = s.size() - 1; i >= 0; i--)
            {
                int x = s[i] - 'a';
                if(!son[p][x]) 
                {
                    break;
                }
                p = son[p][x];
            }

            res.push_back(h[p]);
        }

        return res;
    }
};