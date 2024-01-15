/*
 * @lc app=leetcode.cn id=2201 lang=cpp
 *
 * [2201] 统计可以提取的工件
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    bool st[N][N];

    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        for(auto e : dig)
        {
            st[e[0]][e[1]] = true;
        }

        int res = 0;
        for(auto e : artifacts)
        {
            bool flag = true;
            for(int i = e[0]; i <= e[2]; i++)
                for(int j = e[1]; j <= e[3]; j++)
                    if(!st[i][j]) flag = false;
            if(flag) res++;
        }

        return res;
    }
};
// @lc code=end

