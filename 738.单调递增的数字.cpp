/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
// @lc code=start
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // ：98，一旦出现strNum[i - 1] > strNum[i]的情况（非单调递增），
        //首先想让strNum[i - 1]--，然后strNum[i]给为9，
        //这样这个整数就是89，即小于98的最大的单调递增整数。
        string strNum = to_string(n); // 将数字转换成字符串

        int flag = strNum.size(); // 设置标记位 防止在后面赋值错误。
        for(int i = strNum.size() - 1; i  > 0; i--)
        {
            if(strNum[i - 1] > strNum[i])
            {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for(int i = flag; i < strNum.size(); i++)
        {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
// @lc code=end

