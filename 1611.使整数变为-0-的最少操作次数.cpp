/*
 * @lc app=leetcode.cn id=1611 lang=cpp
 *
 * [1611] 使整数变为 0 的最少操作次数
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> h;
    int dfs(int x)
    {
        if(x <= 1) return x;
            
        if(h.count(x)) return h[x];
        int p = 32;
        for(int i = 31; i >= 0; i--)
        {
            if(x >> i & 1) 
            {
                p = i;
                break;
            }
        }
        int res = dfs(x ^ (3 << (p - 1))) + dfs(1 << (p - 1)) + 1;

        return h[x] = res;
    }

    int minimumOneBitOperations(int n) {      
       
        return dfs(n);
    }
};
// @lc code=end

