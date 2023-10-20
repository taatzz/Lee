/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:

    // 依次将每一个修订号取出来进行比较
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();

        int i = 0, j = 0;
        while(i < m || j < n)
        {
            int x = 0;
            for(; i < m && version1[i] != '.'; i++)
            {
                // 去除前导0
                x = x * 10 + version1[i] - '0';
            }

            int y = 0;
            for(; j < n && version2[j] != '.'; j++)
            {
                y = y * 10 + version2[j] - '0';
            }

            if(x !=y)
                return x > y ? 1 : -1;
        }

        return 0;
    }
};
// @lc code=end

