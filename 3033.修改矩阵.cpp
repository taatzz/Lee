#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();

        for(int j = 0; j < n; j++)
        {
            int mx = 0;
            for(int i = 0; i < m; i++)
            {
                mx = max(mx, nums[i][j]);
            }
            for(int i = 0; i < m; i++)
            {
                if(nums[i][j] == -1)  nums[i][j] = mx;
            }
        }

        return nums;
    }
};