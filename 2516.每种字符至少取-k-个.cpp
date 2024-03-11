/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 *
 * [2516] 每种字符至少取 K 个
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3];
        int n = s.size(), res = 0;
        if(n < k * 2) return -1;

        for(int i = 0; i < n; i++) cnt[s[i] - 'a'] ++;
        for(int i = 0; i < 3; i++) 
            if(cnt[i] < k) return -1;

        vector<pair<int, int>> t(3);
        t[0] = {0, cnt[0] - k};
        t[1] = {0, cnt[1] - k};
        t[2] = {0, cnt[2] - k};
        
        for(int i = 0, j = 0; i < n; i++)
        {
            int u = s[i] - 'a';
            t[u].first++;
            while(j <= i && t[u].first > t[u].second)
            {
                int x = s[j] - 'a';
                t[x].first--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        

        return n - res;
    }
};
// @lc code=end

