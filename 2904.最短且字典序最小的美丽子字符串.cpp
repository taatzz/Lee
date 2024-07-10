#include <string>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string res;
        int cnt = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            cnt += s[i] - '0';
            while(cnt >= k)
            {
                string t = s.substr(j, i - j + 1);
                if(res.size() == 0) res = t;
                else 
                {
                    if(t.size() == res.size()) res = min(res, t);
                    else if(res.size() > t.size()) res = t;
                }

                cnt -= s[j++] - '0';
            }
        }

        return res;
    }
};