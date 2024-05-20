/*
 * @lc app=leetcode.cn id=2584 lang=cpp
 *
 * [2584] 分割数组使乘积互质
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> s;
        
        auto find = [&](int x, unordered_map<int, int>& h)
        {
            for(int i = 2; i <= x / i; i++)
            {
                if(x % i == 0)
                {
                    h[i]++;
                    while(x % i == 0) x /= i;
                }
            }
            if(x > 1) h[x]++;
        };

        for(int i = n - 1; i >= 0; i--)
        {
            find(nums[i], s);
        }

        // 左边全部包含一个质数在数组中的全部数量或者左边不包含该质数
        unordered_map<int, int> h;
        int res = -1, t = s.size(); // 初始时左边全部不包含，初始化成右边的全部质数数量
        for(int i = 0; i < n - 1; i++)
        {
            int x = nums[i];
            for(int j = 2; j <= x / j; j++)
            {
                if(x % j == 0)
                {
                    h[j]++;
                    // 左边第一次包含该质数，满足的数量减一
                    if(h[j] == 1) t--;
                    if(h[j] == s[j]) t++;
                    while(x % j == 0) x /= j;
                }
            }
            if(x > 1)
            {
                h[x]++;
                if(h[x] == 1) t--;
                if(h[x] == s[x]) t++;
            }
            // 满足条件返回答案
            if(t == s.size()) return i;
        }

        return res;
    }
};
// @lc code=end

