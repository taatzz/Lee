#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;


// class Solution {
// public:
//     double minimumAverage(vector<int>& nums) {
//         set<double> h;
//         sort(nums.begin(), nums.end());

//         int n = nums.size();
//         int i = 0, j = n - 1;
//         while(i < j)
//         {
//             h.insert((nums[i] + nums[j]) / 2.0);
//         }

//         return *h.begin();
//     }
// };

// class Solution {
// public:
//     int minimumArea(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();

//         int rows = INT_MAX, rowe = INT_MIN;
//         int cols = INT_MAX, cole = INT_MIN;
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(grid[i][j] == 1) 
//                 {
//                     rows = min(rows, j + 1);
//                     rowe = max(rowe, j + 1);
//                     cols = min(cols, i + 1);
//                     cole = max(cole, i + 1);
//                 }
//             }
//         }
       

//         return (rowe - rows + 1) * (cole - cols + 1);
//     }
// };

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int i = 0;
        while(i < n)
        {
            // cout << i << ' ';
            if(nums[i] > 0)
            {
                if(i + 1 < n && nums[i + 1] < 0)    
                {
                    res += nums[i] - nums[i + 1];
                    i++;
                    if(i + 1 < n && nums[i + 1] < 0 && (i + 1) % 2 == 1)
                    {
                        res += abs(nums[i + 1]);
                        i++;
                    }
                }
                else res += nums[i];
            }
            else
            {
                if(i + 1 < n && nums[i + 1] < 0)
                {
                    res += nums[i] - nums[i + 1];
                    i++;
                    if(i + 1 < n && nums[i + 1] < 0 && (i + 1) % 2 == 1)
                    {
                        res += abs(nums[i + 1]);
                        i++;
                    }
                }
                else res += nums[i];
            }
            i++;
            // cout << res << endl;
        }

        return res;
    }
};