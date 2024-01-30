/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 *
 * [2337] 移动片段得到字符串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        string s = start, t = target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());

        if(s != t) return false;

        // start[i] == L 如果i < j L无法右移直接返回false
        // start[i] == R 如果i > j R无法左移直接返回false
        for(int i = 0, j = 0; i < start.size(); i++)
        {
            if(start[i] == '_') continue;
            while(target[j] == '_') j++;

            if(i != j && (start[i] == 'L') == (i < j))
                return false;
            j++;
        }

        return true;
    }
};
// @lc code=end

