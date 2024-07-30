#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& nums, int target) {

        auto qmi = [&](long long a, long long b, long long m)
        {
            long long res = 1;
            while(b)
            {
                if(b & 1) res = res * a % m;
                a = a * a % m;
                b >>= 1;
            }
            return res;
        };

        vector<int> res;
        int idx = 0;
        for(auto& e : nums)
        {
            int a = e[0], b = e[1], c = e[2], m = e[3];
            if(qmi(qmi(a, b, 10), c, m) == target) res.push_back(idx);
            idx++;
        }

        return res;
    }
};