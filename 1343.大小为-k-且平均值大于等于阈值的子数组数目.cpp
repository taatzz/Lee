/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), sum = 0, res = 0;

        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(i >= k - 1)
            {
                // 窗口左端点
                int j = i - k + 1;
                if(sum / k >= threshold)
                    res ++;
                sum -= arr[j];
            }
        }

        return res;
    }
};
// @lc code=end

