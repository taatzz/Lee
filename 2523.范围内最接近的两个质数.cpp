/*
 * @lc app=leetcode.cn id=2523 lang=cpp
 *
 * [2523] 范围内最接近的两个质数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 1000010;
    bool st[N];
    int p[N], idx;

    void get(int x)
    {
        for(int i = 2; i <= x; i ++)
        {
            if(!st[i]) p[idx++] = i;
            for(int j = 0; p[j] <= x / i; j++)
            {
                st[p[j] * i] = 1;
                if(i % p[j] == 0) break;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        get(right);

        int l = lower_bound(p, p + idx, left) - p;
        int r = upper_bound(p, p + idx, right) - p;

        vector<int> res(2);
        if(r - l <= 1) return {-1, -1};
        else
        {
            int min_num = INT_MAX;
            for(int i = l + 1; i < r; i++)
            {
                if(p[i] - p[i - 1] < min_num)
                {
                    min_num = p[i] - p[i - 1];
                    res[0] = p[i - 1], res[1] = p[i];
                }
            }
        }
        
        return res;
    }
};  
// @lc code=end

