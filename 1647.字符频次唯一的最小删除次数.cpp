/*
 * @lc app=leetcode.cn id=1647 lang=cpp
 *
 * [1647] 字符频次唯一的最小删除次数
 */

// @lc code=start
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int cnt[26];

    int minDeletions(string s) {
        for(auto e : s) cnt[e - 'a']++;

        unordered_set<int> h;
        // 对于当前元素频次如果在前面已经出现过，就需要去减少，最多减少到0
        int res = 0;
        for(int i = 0; i < 26; i++)
        {
            int x = cnt[i];
            while(h.find(x) != h.end() && x)
            {
                res++;
                x--;
            }
            h.insert(x);
        }

        return res;
    }
};
// @lc code=end

