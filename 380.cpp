#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// t1
// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) {
//         unordered_map<int, int> h;

//         for(auto e : nums) h[e]++;
//         int res = 0;
//         for(auto e : h) res = max(res, e.second)      ;

//         return res;
//     }
// };

// t2
// class Solution {
// public:
//     vector<int> beautifulIndices(string s, string a, string b, int k) {
//         int m = a.size();
//         int n = s.size();
//         vector<int> t1, t2;

//         for(int i = m - 1; i < n; i++)
//         {
//             int j = i - m + 1;
//             string t = s.substr(j, m);
//             if(t == a) t1.push_back(j);
//         }

//         m = b.size();
//         for(int i = m - 1; i < n; i++)
//         {
//             int j = i - m + 1;
//             string t = s.substr(j, m);
//             if(t == b) t2.push_back(j);
//         }

//         vector<int> res;
//         for(auto e : t1)
//         {
//             for(int i = 0; i < t2.size(); i++)
//                 if(abs(e - t2[i]) <= k)
//                 {
//                     res.push_back(e);
//                     break;
//                 }
//         }

//         return res;
//     }
// };

// t3
class Solution {
public:
    typedef unsigned long long ULL;
    static const int N = 500010, P = 131;
    ULL h1[N], h2[N], h3[N], p[N];
    
    ULL get1(int l, int r)
    {
        return h1[r] - h1[l - 1] * p[r - l + 1];
    }
    
    ULL get2(int l, int r)
    {
        return h2[r] - h2[l - 1] * p[r - l + 1];
    }
    
    ULL get3(int l, int r)
    {
        return h3[r] - h3[l - 1] * p[r - l + 1];
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int m = a.size();
        int n = s.size();
        vector<int> t1, t2;
        
        p[0] = 1, h1[0] = 1;
        for(int i = 1; i <= s.size(); i++)
        {
            p[i] = p[i - 1] * P;
            h1[i] = h1[i - 1] * P + s[i - 1];
        }
        
        h2[0] = 1;
        for(int i = 1; i <= a.size(); i++)
        {
            h2[i] = h2[i - 1] * P + a[i - 1];
        }
        
        h3[0] = 1;
        for(int i = 1; i <= b.size(); i++)
        {
            h3[i] = h3[i - 1] * P + b[i - 1];
        }
        

        for(int i = m - 1; i <= n; i++)
        {
            int j = i - m + 1;
            if(get2(1, a.size()) == get1(j + 1, i + 1)) t1.push_back(j);
        }

        m = b.size();
        for(int i = m - 1; i <= n; i++)
        {
            int j = i - m + 1;
            if(get3(1, b.size()) == get1(j + 1, i + 1)) t2.push_back(j);
        }    
        
        
        vector<int> res;
        if(t2.size() == 0) return{};
        
        for(auto e : t1)
        {
            auto it = lower_bound(t2.begin(), t2.end(), e) - t2.begin();
            if(it - 1 >= 0)
            {
                if(abs(t2[it - 1] - e) <= k)
                {
                    res.push_back(e);
                    continue;
                }
            }
            if(it >= 0 && it < t2.size())
                if(abs(t2[it] - e) <= k) 
                {
                    res.push_back(e);
                    continue;
                }
            if(it + 1 < t2.size())
                if(abs(t2[it + 1] - e) <= k) 
                {
                     res.push_back(e);
                    continue;
                }
        }

        return res;
    }
};
