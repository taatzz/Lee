/*
 * @lc app=leetcode.cn id=2718 lang=cpp
 *
 * [2718] 查询后矩阵的和
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col;

        long long res = 0;
        int k = queries.size();

        for(int i = k - 1; i >= 0; i--)
        {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2];
            if(a == 0)
            {
                if(row.find(b) != row.end()) continue;
                else
                {
                    int m = col.size();
                    res += (long long)(n - m) * c;
                }
                row[b]++;
            }
            else
            {
                if(col.find(b) != col.end()) continue;
                else
                {
                    int m = row.size();
                    res += (long long)(n - m) * c;
                }
                col[b]++;
            }
        }

        return res;
    }
};
// @lc code=end

