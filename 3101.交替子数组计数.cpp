#include <vector>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long res = 0;
        while(i < n)
        {
            int start = i;
            i++;
            while(i < n && nums[i] != nums[i - 1]) i++;
            long long t = i - start;
            res += (t + 1) * t / 2;
        }

        return res;
    }
};