/*
 * @lc app=leetcode.cn id=2707 lang=cpp
 *
 * [2707] 字符串中的额外字符
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> h(dictionary.begin(), dictionary.end());

        vector<int> f(n + 1);

        for(int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1] + 1;
            for(int j = i; j > 0; j --)
            {
                string t = s.substr(j - 1, i - j + 1);
                if(h.find(t) != h.end())
                {       
                    f[i] = min(f[i], f[j - 1]);
                }
            }
        }
        // for(auto e : f) cout << e << " ";

        return f[n];
    }
};
// @lc code=end

