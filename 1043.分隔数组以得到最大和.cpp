/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> mem(n, -1);
        function<int(int)> dfs = [&](int i)
        {   
            if(i < 0) return 0;

            if(mem[i] != -1) return mem[i];
            int res = 0, mx = 0;
            for(int j = i; i - j + 1 <= k && j >= 0; j--)
            {
                mx = max(mx, arr[j]);
                res = max(res, dfs(j - 1) + (i - j + 1) * mx);
            }

            return mem[i] = res;
        };

        return dfs(n - 1);
    }
};
// @lc code=end

