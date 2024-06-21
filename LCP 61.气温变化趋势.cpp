#include <vector>

using namespace std;

class Solution {
public:
    int temperatureTrend(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> cnta(n), cntb(n);
        for(int i = 1; i < n; i++)
        {
            cnta[i] = a[i] > a[i - 1] ? 1 : -1;
            if(a[i] == a[i - 1]) cnta[i] = 0;
            cntb[i] = b[i] > b[i - 1] ? 1 : -1;
            if(b[i] == b[i - 1]) cntb[i] = 0;
        }

        int res = 0, i = 1;
        while(i < n)
        {
            int start = i;
            if(cnta[i] == cntb[i])
            {
                i++;
                while(i < n && cnta[i] == cntb[i]) i++;
                res = max(res, i - start);
            }
            else i++;
        }

        return res;
    }
};