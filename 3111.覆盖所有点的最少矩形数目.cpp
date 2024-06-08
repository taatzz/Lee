#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& nums, int w) {
        sort(nums.begin(), nums.end(), 
        [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; });

        int res = 0, i = 0, n = nums.size();
        while(i < n)
        {   
            int start = i;
            i++;
            while(i < n && nums[i][0] - nums[start][0] <= w) i++;

            res++;
        }

        return res;
    }
};