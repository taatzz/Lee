/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int k, int n) {
        int i = 0, cnt = 1;

        vector<int> res(n);
        while(k > 0)
        {
            if(k >= cnt) res[i] += cnt;
            else res[i] += k, k = 0;
            k -= cnt;
            i++, cnt++;
            if(i >= n) i = 0;
        }

        return res;
    }
};
// @lc code=end

