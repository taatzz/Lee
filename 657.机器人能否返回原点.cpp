/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> tmp(2, 0) ;

        for(auto e : moves)
        {
            if(e == 'U')
                tmp[0] += 1;
            else if(e == 'D')  
                tmp[0] -= 1;
            else if(e == 'R')
                tmp[1] += 1;
            else 
                tmp[1] -= 1;
        }
        return tmp[0] == 0 && tmp[1] == 0;
    }
};
// @lc code=end

