/*
 * @lc app=leetcode.cn id=1575 lang=cpp
 *
 * [1575] 统计所有可行路径
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 210, mod = 1e9 + 7;
    long long mem[N][N];

    int dfs(vector<int>& nums, int x, int end, int f)
    {
        if(mem[x][f] != -1) return mem[x][f]; 

        // 当前位置的汽油无法到达终点则永远无法到达终点，直接返回
        int need = abs(nums[x] - nums[end]);
        if(need > f) 
        {
            mem[x][f] = 0;
            return 0;
        }

        int n = nums.size();
        long long res = x == end ? 1 : 0;
        for(int i = 0; i < n; i++)
        {
            if(i == x) continue;
            int t = abs(nums[i] - nums[x]);
            // 剩余汽油大于要去点需要的汽油时才会继续，不然会递归超出记忆化数组
            if(f >= t)
            {
                res += dfs(nums, i, end, f - t);
                res %= mod;
            }
        }

        mem[x][f] = res;
        return res;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(mem, -1, sizeof mem);
       
        return dfs(locations, start, finish, fuel);
    }
};
// @lc code=end

