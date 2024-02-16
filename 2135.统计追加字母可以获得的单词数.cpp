/*
 * @lc app=leetcode.cn id=2135 lang=cpp
 *
 * [2135] 统计追加字母可以获得的单词数
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 因为可以进行排序，所以我们直接将字符串排序，然后我们对每一个查询字符串去掉一个字符然后在哈希表中
    // 查找是否存在，实现时不用对每一个字符串进行排序，将字符串对应成一个二进制数

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> h;
        for(auto& e : startWords)
        {
            int x = 0;
            for(int i = 0; i < e.size(); i++)
            {
                int t = e[i] - 'a';
                x |= (1 << t);
            }
            h.insert(x);
        }

        int res = 0;

        for(auto& word : targetWords)
        {
            int x = 0;
            for(int i = 0 ; i < word.size(); i++) x |= (1 << (word[i] - 'a'));

            for(auto ch : word)
            {
                if(h.count(x ^ (1 << (ch - 'a'))))
                {
                    res ++;
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

