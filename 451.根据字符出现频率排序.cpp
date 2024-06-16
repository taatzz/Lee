/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(200);

        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            cnt[s[i] - '0']++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
        for(int i = 0; i < cnt.size(); i++)
        {
            if(cnt[i])
                q.emplace(cnt[i], i);
        }

        string res;
        while(q.size())
        {
            auto t = q.top();
            q.pop();
            while(t.first--)
            {
                res += t.second + '0';
            }
        }

        return res;
    }
};
// @lc code=end

