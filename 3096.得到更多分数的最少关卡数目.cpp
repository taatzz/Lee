#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int s[N];

    int minimumLevels(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + (nums[i - 1] == 0 ? -1 : 1);

        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(s[i + 1] > s[n] - s[i + 1])
            {
                res = i + 1;
                break;
            }
        }

        return res == n || res == INT_MAX ? -1 : res;
    }
};