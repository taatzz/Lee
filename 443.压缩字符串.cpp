/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;

        int i = 0, left = 0; // 保存写入字符串的位置和重复字符串的最左端位置

        for(int j = 0; j < chars.size() - 1; i++)
        {
            if(j == chars.size() - 1 || chars[j] != chars[j + 1])
            {
                chars[i++] = chars[j];
                int num = j - left + 1;
                if(num > 1) // 长度大于1
                {
                    int tmp = i;
                    while(num)
                    {
                        chars[i++] = num % 10 + '0';
                        num /= 10;
                    }
                    reverse(&chars[tmp], &chars[i]); // 如果重复字符大于10反转
                }
                left = j + 1; // 更新最左端位置
            }
        }

        return i;
    }
};
// @lc code=end

