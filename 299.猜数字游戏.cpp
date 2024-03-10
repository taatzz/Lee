/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> h1, h2;

        int cnt = 0, res = 0;
        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i]) cnt++;
            h1[secret[i]]++;
            h2[guess[i]]++;
        }

        for(auto& [k, e] : h2)
        {
            if(h1.count(k))
            {
                res += min(h1[k], h2[k]);
            }
        }
        res -= cnt;

        return to_string(cnt) + "A" + to_string(res) + "B";
    }
};
// @lc code=end

