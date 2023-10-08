/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        vector<int> tmp(ratings.size(), 1);

        for(int i = 1; i < ratings.size(); i++)
        {   
            if(ratings[i] > ratings[i - 1])
                tmp[i] = tmp[i - 1] + 1;
        }

        for(int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
                tmp[i] = tmp[i + 1] + 1;
        }

        for(auto e : tmp)
            res += e;
        return res;
    }
};
// @lc code=end

