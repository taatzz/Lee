/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include  <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> res(2, INT_MAX);
        unordered_map<char, int> h;
        unordered_map<char, int> hs;
        for(auto e : t) hs[e]++;
        
        int cnt = 0;

        for(int i = 0, j = 0; i < n; i++)
        {
            h[s[i]]++;
            if(hs.find(s[i]) != hs.end())
            {
                if(h[s[i]] == hs[s[i]]) cnt++; // 统计当前s中可以匹配t的字符个数
            }
            
            while(cnt == hs.size()) // 可以匹配所有字符时，说明我们找到了一个合法子串
            {
                // 尝试更新左端点找到一个最短的子串
                h[s[j]]--;
                if(hs.find(s[j]) != hs.end())
                {
                    if(h[s[j]] < hs[s[j]]) // 左端点的字符更新后如果无法满足和t匹配更新答案和种类数
                    {
                        cnt--;
                        if(i - j + 1 < res[0])
                        {
                            res[0] = i - j + 1;
                            res[1] = j;
                        }
                    }
                }
                j++;
            }
        }

        if(res[0] == INT_MAX) return ""; // 无法匹配当前的t字符串

        return s.substr(res[1], res[0]);
    }
};
// @lc code=end

