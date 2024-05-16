/*
 * @lc app=leetcode.cn id=1439 lang=cpp
 *
 * [1439] 有序矩阵中的第 k 个最小数组和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> a = {0};
        for(auto& row : mat)
        {
            vector<int> b;
            for(auto x : a)
            {
                for(int y : row)
                    b.push_back(x + y);
            }
            sort(b.begin(), b.end());
            if(b.size() > k) b.resize(k);
            a = move(b);
        }

        return a.back();
    }
};
// @lc code=end

