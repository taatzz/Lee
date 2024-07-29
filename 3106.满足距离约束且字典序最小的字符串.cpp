#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string res = s;
        
        for(int i = 0; i < n && k; i++)
        {
            int x = min(s[i] - 'a', 'z' - s[i] + 1);
            if(x <= k)
            {
                res[i] = 'a';
                k -= x;
            }
            else
            {
                res[i] = s[i] - k;
                k = 0;
            }
        }

        return res;
    }
};