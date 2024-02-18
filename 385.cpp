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
//     bool isPrefixAndSuffix(string s1, string s2)
//     {
//         if(s1.size() <= s2.size())
//         {
//             for(int i = 0, j = 0; i < s1.size(); i++)
//                 if(s1[i] == s2[j]) j++;
//                 else return false;
//             for(int i = s1.size() - 1, j = s2.size() - 1; i >= 0; i--)
//                 if(s1[i] == s2[j]) j--;
//                 else return false;
//         }
//         else return false;
        
//         return true;
//     }
    
//     int countPrefixSuffixPairs(vector<string>& words) {
//         int n = words.size(), res = 0;
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i + 1; j < n; j++)
//             {
//                 if(isPrefixAndSuffix(words[i], words[j])) res++;
//             }
//         }
        
//         return res;
//     }
// };


//T2
// class Solution {
// public:
//     static const int N = 100010;
//     int son[N][10], index;
    
//     void Insert(string a)
//     {
//         int p = 0;
//         for(int i = 0; i < a.size(); i++)
//         {
//             int x = a[i] - '0';
//             // 当前路径不存在就创建
//             if(!son[p][x]) son[p][x] = ++index;
//             p = son[p][x];
//         }
//     }

//     int check(string s)
//     {
//         int p = 0, cnt = 0;
//         for(int i = 0; i < s.size(); i++)
//         {
//             int x = s[i] - '0';
//             if(!son[p][x]) return i;
//             p = son[p][x];
//         }
        
//         return s.size();
//     }

//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int n1 = arr1.size(), n2 = arr2.size();
//         for(int i = 0; i < n2; i++)
//         {
//             string a = to_string(arr2[i]);
//             Insert(a);
//         }

//         int res = 0;
//         for(int i = n1 - 1; i >= 0; i--)
//         {
//            res = max(res, check(to_string(arr1[i])));
//         }

//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     unordered_map<int, int> h;

//     void find(vector<vector<int>>& nums, int x, int y)
//     {
//         int m = nums.size(), n = nums[0].size();
//         h[nums[x][y]]++;
//         int t = nums[x][y];
//         int tmp = t;

//         for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
//         {
//             tmp = tmp * 10 + nums[i][j];
//             h[tmp]++;
//         }

//         tmp = t;
//         for(int i = x - 1; i >= 0; i--)
//         {
//             tmp = tmp * 10 + nums[i][y];
//             h[tmp]++;
//         }

//         tmp = t;
//         for(int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++)
//         {
//             tmp = tmp * 10 + nums[i][j];
//             h[tmp]++;
//         }

//         tmp = t;
//         for(int i = x + 1, j = y + 1; i < m && j < n; i++, j++)
//         {
//             tmp = tmp * 10 + nums[i][j];
//             h[tmp]++;
//         }

//         tmp = t;
//         for(int i = x + 1; i < m; i++)
//         {
//             tmp = tmp * 10 + nums[i][y];
//             h[tmp]++;
//         }

//         tmp = t;
//         for(int i = x + 1, j = y - 1; i < m && j >= 0; i++, j--)
//         {
//             tmp = tmp * 10 + nums[i][j];
//             h[tmp]++;
//         }

//         tmp = t;
//         for(int j = y - 1; j >= 0; j--)
//         {
//             tmp = tmp * 10 + nums[x][j];
//             h[tmp]++;
//         }

//         tmp = t;
//         for(int j = y + 1; j < n; j++)
//         {
//             tmp = tmp * 10 + nums[x][j];
//             h[tmp]++;
//         }
//     }
    
//     bool check(int x)
//     {
//         // 小于2的数不是质数
//         if(x <= 1)
//             return false;
//         for(int i = 2; i <= x / i; i++)
//         {
//             if(x % i == 0)
//                 return false;
//         }

//         return true;
//     }
    
//     int mostFrequentPrime(vector<vector<int>>& mat) {
//         for(int i = 0; i < mat.size(); i++)
//         {
//             for(int j = 0; j < mat[0].size(); j++)
//             {
//                 find(mat, i, j);
//             }
//         }

//         int res = -1, mx = 0;
//         for(auto& [k, v] : h)
//         {
//             if(k > 10)
//             {
//                 if(check(k)) 
//                 {
//                     if(v > mx) 
//                     {
//                         mx = max(mx, v);
//                         res = k;
//                     }
//                     else if(v == mx)
//                     {
//                         res = max(res, k);
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };

// T4 后续加强数据可能会超时
class Solution {
public: 
    static const int N = 500010;
    int son[N][26], index, cnt[N];
    long long res = 0;

    bool check(string a, string b)
    {
        if(a.size() == 0) return false;
        for(int i = a.size() - 1, j = b.size() - 1; i >= 0; i--)
            if(a[i] == b[j]) j--;
            else return false;
        return true;
    }

    void insert(string s)
    {
        int p = 0;
        string a;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            a += s[i];
            if(!son[p][u]) son[p][u] = ++index;
            p = son[p][u];
        }

        cnt[p]++;
    }

    void query(string s)
    {
        int p = 0;
        string t;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) break;
            if(cnt[p])
            {
                if(check(t, s))
                {
                    res += cnt[p];
                }
            }
            t += s[i];
            p = son[p][u];
        }
        if(cnt[p] && check(t, s))
        {
            res += cnt[p];
        }
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        for(auto e : words)
        {
            query(e);
            insert(e);
        }

        return res;
    }
};