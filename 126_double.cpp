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
//     int sumOfEncryptedInt(vector<int>& nums) {
//         int n = nums.size(), res = 0;

//         for(int i = 0; i < n; i++)
//         {
//             int t = nums[i];
//             int mx = 0, cnt = 0;
//             while(t)
//             {
//                 cnt++;
//                 mx = max(mx, t % 10);
//                 t /= 10;
//             }

//             int sum = 0;
//             while(cnt--) sum = sum * 10 + mx;
//             res += sum;
//         }

//         return res;
//     }
// };

// T2
// class Solution {
// public:
//     typedef pair<int, int> PII;
//     static const int N = 100010;
//     bool st[N];

//     vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         priority_queue<PII, vector<PII>, greater<PII>> q;

//         long long sum = 0;
//         for(int i = 0 ; i < n; i++)
//         {
//             sum += nums[i];
//             q.push({nums[i], i});
//         }

//         int m = queries.size();
//         vector<long long> res;
//         for(auto& e : queries)
//         {
//             int idx = e[0], k = e[1];
//             if(!st[idx])
//             {
//                 st[idx] = 1;
//                 sum -= nums[idx];
//             }
//             while(q.size() && k)
//             {
//                 auto t = q.top();
//                 q.pop();
//                 if(st[t.second]) continue;
//                 st[t.second] = 1;
//                 sum -= t.first;
//                 k--;
//             }
//             res.push_back(sum);
//         }

//         return res;
//     }
// };

// T3
class Solution {
public:
    int cnt[26];
    // 贪心，对于总得分数来说，我们每次都选择出现次数最小的(因为最后的分数是不会改变的)，排序之后替换问号
    string minimizeStringValue(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] != '?') cnt[s[i] - 'a']++;
        }

        string res;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '?')
            {
                int mn = 1e5 + 10, idx = 0;
                for(int j = 0; j < 26; j++)
                {
                    if(cnt[j] < mn)
                    {
                        mn = cnt[j];
                        idx = j;
                    }
                }
                res += 'a' + idx;
                cnt[idx]++;
            }
        }
        
        sort(res.begin(), res.end());
        for(int i = 0, j = 0; i < s.size(); i++) 
        {
            if(s[i] == '?') s[i] = res[j++];
        }

        return s;
    }
};