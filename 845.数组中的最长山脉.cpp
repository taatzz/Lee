/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
#include <vector>

using namespace std;

// class Solution {
// public:
//     int longestMountain(vector<int>& arr) {
//         int n = arr.size(), res = 0;

//         int i = 0;

//         while(i < n - 1)
//         {
//             int flag = 0;
//             int start = i;
//             if(arr[i] >= arr[i + 1]) // 非递增直接跳过
//             {
//                 i++;
//                 continue;
//             }
//             while(i + 1 < n && arr[i] < arr[i + 1])// 山脉左半边
//             {
//                 i++;
//             }

//             while(i + 1 < n && arr[i] > arr[i + 1]) // 山脉右半边，只要符合两个循环，长度一定大于3
//             {
//                 i++;
//                 res = max(res, i - start + 1);
//             }
//         }

//         return res;
//     }
// };
// @lc code=end


class Solution {
public:

    // dp[i] 表示可以向左侧或者右侧扩展的长度
    // 左侧 arr[i] > arr[i-1] dp[i] = dp[i-1] + 1  否则 dp[i] = 0 右侧同理
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp_left(n, 0), dp_right(n, 0);

        for(int i = 1; i < n; i++)
        {
            dp_left[i] = arr[i] > arr[i-1] ? dp_left[i-1] + 1 : 0;
        }

        for(int i = n - 2; i >= 0; i--)
        {
            dp_right[i] = arr[i + 1] < arr[i] ? dp_right[i+1] + 1 : 0;
        }

        int res = 0;
        for(int i = 1; i < n; i++)
        {
            // 左右两侧第一个元素都是不会被记录的，但是山峰是多记录一次的所以只需要+1
            if(dp_right[i] && dp_left[i])
                res = max(res, dp_right[i] + dp_left[i] + 1);
        }

        return res;
    }
};
