#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];
    int mod = 1e9 + 7; 

    int waysToSplit(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + nums[i - 1];
        }

        long long res = 0;
        for(int i = 1; i < n - 1 && s[i] * 3 <= s[n]; i++)
        {
            int l = i + 1, r = n - 1;
            int x1 = s[i];
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(s[mid] - x1 >= x1) r = mid;
                else l = mid + 1;
            }
            if(s[l] - x1 < x1) continue;
            int j = l;
            
            l = i + 1, r = n - 1;
            while(l < r)
            {
                int mid = (l + r + 1) >> 1;
                if(s[mid] - x1 <= s[n] - s[mid]) l = mid;
                else r = mid - 1;
            }
            if(s[n] - s[l] < s[l] - x1) continue;
            res += l - j + 1;
            res %= mod;
        }

        return res;
    }
};