/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string tmp = to_string(n);

        for(int i = tmp.size() - 1; i >= 0; i--)
        {
            for(int j = tmp.size() - 1; j > i; j--)
            {
                if(tmp[j] > tmp[i])
                {
                    swap(tmp[i], tmp[j]);
                    reverse(tmp.begin() + i + 1, tmp.end());
                    long ans = stol(tmp);

                    return ans > INT_MAX ? -1 : ans;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

