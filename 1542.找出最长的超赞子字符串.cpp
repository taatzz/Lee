#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> h;
        h[0] = -1;

        int n = s.size(), sum = 0;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            sum ^= 1 << (s[i] - '0');
            if(h.count(sum))
                res = max(res, i - h[sum]);
            else h[sum] = i;

            for(int j = 0; j < 10; j++)
            {
                if(h.count((sum ^ (1 << j))))
                    res = max(res, i - h[(sum ^ (1 << j))]);
            }
            
        }

        return res;
    }
};