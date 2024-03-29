#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static const int mod = 1e9 + 7;

    int qmi(int a, int b)
    {
        long long res = 1;
        while(b)
        {
            if(b & 1) res = res * a % mod;
            b >>= 1;
            a = (long long) a * a % mod;
        }

        return res;
    }

    int countAnagrams(string s) {
        int n = s.size();

        int i = 0;
        long long res = 1, mul = 1;
        while(i < n)
        {
            vector<int> cnt(26);
            int start = i;
            while(i < n && s[i] != ' ') 
            {
                mul = mul * ++cnt[s[i] - 'a'] % mod;
                res = res * (i - start + 1) % mod;
                i++;
            }
            i++;
        }

        return res * qmi(mul, mod - 2) % mod;;
    }
};