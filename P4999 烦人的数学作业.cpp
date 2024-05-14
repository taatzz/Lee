#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

// const int mod = 1e9 + 7;
// int mem[20][200];

// int dfs(string s, int x, int sum, bool is_limit)
// {
//     int n = s.size();
//     if(x >= n)
//         return sum;

//     if(!is_limit && mem[x][sum] != -1) return mem[x][sum];

//     int res = 0;
//     int hi = is_limit ? s[x] - '0' : 9;
//     for(int i = 0; i <= hi; i++)
//     {
//         res = (res + dfs(s, x + 1, sum + i, is_limit && i == hi)) % mod;
//     }
    
//     if(!is_limit) mem[x][sum] = res;

//     return res;
// }

// void solve()
// {
//     long long a, b;
//     cin >> a >> b;
//     a -= 1;
//     string s1 = to_string(a), s2 = to_string(b);

//     memset(mem, -1, sizeof mem);
//     a = dfs(s2, 0, 0, true);
//     memset(mem, -1, sizeof mem);
//     b = dfs(s1, 0, 0, true);

//     cout << (a - b + mod) % mod << endl;
// }

// int main()
// {
//     int r;
//     cin >> r;
//     while(r --) solve();

//     return 0;
// }

// long long mem[20][20];

// long long dfs(string s, int x, long long sum, int k, bool is_num, bool is_limit)
// {
//     int n = s.size();
//     if(x >= n) 
//     {
//         return sum;
//     }

//     if(is_num && !is_limit && mem[x][sum] != -1) return mem[x][sum];
//     long long res = 0;
//     if(!is_num) res += dfs(s, x + 1, sum, k, false, false);

//     int hi = is_limit ? s[x] - '0' : 9;
//     for(int i = 1 - is_num; i <= hi; i++)
//     {
//         res += dfs(s, x + 1, sum + (i == k), k, true, is_limit && i == hi);
//     } 

//     if(is_num && !is_limit) mem[x][sum] = res;

//     return res;
// }

// int main()
// {
//     long long a, b;
//     cin >> a >> b;
//     a -= 1;
//     string s1 = to_string(a), s2 = to_string(b);

//     for(int i = 0; i <= 9; i++)
//     {
//         memset(mem, -1, sizeof mem);
//         a = dfs(s1, 0, 0, i, false, true);
//         memset(mem, -1, sizeof mem);
//         b = dfs(s2, 0, 0, i, false, true);
//         if(i != 9)
//             cout << b - a << " ";
//         else cout << b - a;
//     }

//     return 0;
// }

// int k;
// long long mem[70][70];

// long long dfs(string s, int x, long long sum, bool is_limit)
// {
//     int n = s.size();
//     if(x >= n)
//     {
//         return sum == k ? 1 : 0;
//     }
//     if(mem[x][sum] != -1 && !is_limit) return mem[x][sum];

//     long long res = 0;
//     int hi = is_limit ? s[x] - '0' : 1;
//     for(int i = 0; i <= hi; i++)
//     {
//         res += dfs(s, x + 1, sum + (i == 1), is_limit && i == hi);
//     }

//     if(!is_limit) mem[x][sum] = res;

//     return res;
// }

// int main()
// {
//     memset(mem, -1, sizeof mem);
//     long long n;
//     cin >> n >> k;
//     string s;

//     while(n)
//     {
//         if(n & 1) s += '1';
//         else s += '0';
//         n >>= 1;
//     }
//     reverse(s.begin(), s.end());
    
//     cout << dfs(s, 0, 0, true) << endl;
    
//     return 0;
// }

