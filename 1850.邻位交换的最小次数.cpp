/*
 * @lc app=leetcode.cn id=1850 lang=cpp
 *
 * [1850] 邻位交换的最小次数
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;
        for(int i = 0; i < k; i++)
        {
            next_permutation(target.begin(), target.end());
        }

        int n = num.size();
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            if(num[i] != target[i])
            {
                for(int j = i + 1; j < n; j++)
                {
                    if(num[j] == target[i])
                    {
                        for(int k = j - 1; k >= i; k--)
                        {
                            res++;
                            swap(num[k], num[k + 1]);
                        }
                        break;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

