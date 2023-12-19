/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int l = 0, r = m - 1
        ;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            int j = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if(mat[mid][j] > mat[mid + 1][j]) r = mid;
            else l = mid + 1;
        }
        int x = max_element(mat[l].begin(), mat[l].end()) - mat[l].begin();
        vector<int> res{l, x};

        return res;
    }
};
// @lc code=end

