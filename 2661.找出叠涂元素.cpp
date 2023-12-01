/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int> > hash;

        int m = mat.size(), n = mat[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                hash[mat[i][j]] = { i, j };
            }
        }

        vector<int> row(m, 0), col(n, 0);

        for(int i = 0; i < m * n; i++)
        {
            auto t = hash[arr[i]];

            int r = t.first, c = t.second;

            row[r]++, col[c]++;
            if(row[r] == n || col[c] == m)
                return i;
        }

        return -1;
    }
};
// @lc code=end

