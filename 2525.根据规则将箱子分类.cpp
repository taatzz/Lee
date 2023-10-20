/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = 1L * length * width * height; // 将编译器的存储变为long long

        bool flag1 = false, flag2 = false;

        if(length >= 10000 || width >= 10000 || height >= 10000 || vol >= 1000000000)
            flag1 = true;
        if(mass >= 100)
            flag2 = true;
        if(flag1 && flag2)
            return "Both";
        else if(flag1 || flag2)
        {
            if(flag1)
                return "Bulky";
            else
                return "Heavy";
        }
        else
            return "Neither";
    }
};
// @lc code=end

