/*
 * @lc app=leetcode.cn id=2048 lang=cpp
 *
 * [2048] 下一个更大的数值平衡数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 10;

    bool check(int x)
    {
        vector<int> tmp(N);

        while(x)
        {
            tmp[x % 10]++;
            x /= 10;
        }

        for(int i = 0; i < tmp.size(); i++)
        {
            if(tmp[i] && tmp[i] != i) return false;
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        // 符合题意的最大的数值平衡树 1444422， 如果所有数都不符合直接返回-1
        for(int i = n + 1; i < 1444422; i++)
        {
            if(check(i)) return i;
        }

        return -1;
    }
};
// @lc code=end

