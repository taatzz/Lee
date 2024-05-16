/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 值域二分
        long long l = 1, r = (long long)m * n;
        // 数据范围接近1e9, 那么只能选择小于线性的时间复杂度 -> 二分
        // 依据题意相当于一个每行都递增，每列同样递增的矩阵，那么对于一个数x如果某一行的一列小于x那么当前列的前面行的所有行都小于x
        // 那么就相当于在矩阵中有一条分界线左上角的数据全部小于x，那么我们可以二分答案，看当前的答案是否符合k
        auto check = [&](long long x)
        {
            long long i = m, j = 1, cnt = 0;
            while(i >= 1 && j <= n)
            {
                // 当前行的j列小于x，cnt + 前面的所有行
                if(i * j <= x)
                {
                    j++;
                    cnt += i;
                }
                else i--; // 当前列不满足了，看看下一行当前列是否满足
            }

            return cnt >= k;
        };

        while(l < r)
        {
            long long mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

