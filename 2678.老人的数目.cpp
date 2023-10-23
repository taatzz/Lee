/*
 * @lc app=leetcode.cn id=2678 lang=cpp
 *
 * [2678] 老人的数目
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size(), res = 0;

        for(int i = 0; i < n; i++)
        {
            int age = (details[i][11] - '0') * 10 + details[i][12] - '0';
            if(age > 60)
                res++;
        }

        return res;
    }
};
// @lc code=end

