/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    // 避免浮点数进行运算 num/3 等价于(num + 2) / 3
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        long long res = 0;

        for(auto e : nums)
        {
            q.push(e);
        }

        while(k--)
        {
            int num = q.top();
            q.pop();
            res += num;
            q.push((num + 2) / 3);
        }

        return res;
    }
};
// @lc code=end

