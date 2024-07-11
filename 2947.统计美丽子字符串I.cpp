#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        vector<int> cnt(n + 1);
        unordered_set<char> h = { 'a','e','i','o','u' };
        for(int i = 0; i < n; i++)
        {
            cnt[i + 1] = cnt[i] + h.count(s[i]); 
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                int len = i - j + 1, x = cnt[i + 1] - cnt[j];
                if((x * (len - x)) % k == 0 && x == len - x) res++;
            }
        }

        return res;
    }
};