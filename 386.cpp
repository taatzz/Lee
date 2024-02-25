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

using namespace std;

// T1
// class Solution {
// public:
//     bool isPossibleToSplit(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int> h;

//         for(int i = 0; i < n; i++)
//         {
//             h[nums[i]]++;
//             if(h[nums[i]] > 2) return false;
//         }

//         return true;
//     }
// };


// T2
// class Solution {
// public:
//     long long largestSquareArea(vector<vector<int>>& left, vector<vector<int>>& right) {
//         int n = left.size();

//         long long res = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int ax1 = left[i][0], ay1 = left[i][1];
//             int ax2 = right[i][0], ay2 = right[i][1];
//             for(int j = i + 1; j < n; j++)
//             {
//                 int bx1 = left[j][0], by1 = left[j][1];
//                 int bx2 = right[j][0], by2 = right[j][1];
//                 if(max(ax1, bx1) <= min(ax2, bx2) && max(ay1, by1) <= min(ay2, by2)) 
//                 {
//                     // int Max_X = max(ax2, bx2);                          //右边界
//                     // int Min_X = min(ax1, bx1);                          //下边界

//                     // int Max_Y = max(by1, by2);                          //上边界
//                     // int Min_Y = min(ay1, ay2);                          //下边界

//                     int width = min(ax2, bx2) - max(ax1, bx1);
//                     int height = min(ay2, by2) - max(ay1, by1);
//                     int x = min(width, height);
//                     res = max(res, (long long)x * x);
//                 }
//             }
//         }

//         return res;
//     }
// };


// T3
class Solution {
public:
    bool check(vector<int>& nums, vector<int>& change, int x)
    {
        int n = nums.size();
        vector<int> st(n, -1);
        // 一定是在最后在一个可以标记的时刻在进行标记，否则就什么都不做，让时间 + 1，留给后面的可以进行标记的点
        for(int t = 0; t < x; t++) st[change[t] - 1] = t;

        int cnt = 0, sum = 0;
        for(int i = 0; i < x; i++)
        {
            int idx = change[i] - 1;
            if(i == st[idx])
            {
                if(nums[idx] <= cnt)
                {
                    cnt -= nums[idx];
                    sum++;
                }
            }
            else cnt++;
        }

        return sum == nums.size();
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& change) {
        int n = nums.size(), m = change.size();
        
        int l = 0, r = m + 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, change, mid)) r = mid;
            else l = mid + 1;
        }

        return l > m ? -1 : l;
    }
};