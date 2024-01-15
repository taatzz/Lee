/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 310;
    long long s[N];

    // 对于三元组问题我们尝试固定其中一个元素然后尝试枚举其它两个元素
    // 本题的数据范围较小所以我们可以直接进行暴力枚举
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        for(int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] ^ arr[i - 1];
        }

        int res = 0;
        for(int k = 1; k < n; k++)
        {
            for(int j = k; j >= 0; j--)
            {
                for(int i = j - 1; i >= 0; i--)
                {
                    long long a = s[j] ^ s[i];
                    long long b = s[k + 1] ^ s[j];
                    if(a == b) res++; 
                }
            }
        }

        return res;
    }
};
// @lc code=end

