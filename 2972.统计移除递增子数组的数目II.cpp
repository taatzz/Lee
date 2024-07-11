#include <vector>

using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        long long n = nums.size(), i = 0;
        
        while(i < n - 1 && nums[i] < nums[i + 1]) i++;
        if(i == n - 1) return n * (n + 1) / 2;

        long long res = i + 2;
        for(int j = n - 1; j == n - 1 || nums[j] < nums[j + 1]; j--)
        {
            while(i >= 0 && nums[i] >= nums[j]) i--;
            res += i + 2;
        }

        return res;
    }
};