/*
 * @lc app=leetcode.cn id=1733 lang=cpp
 *
 * [1733] 需要教语言的最少人数
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, unordered_set<int>> h1, h2;
        for(int i = 1; i <= languages.size(); i++)
        {
            for(int j = 0; j < languages[i - 1].size(); j++)
                h1[i].insert(languages[i - 1][j]);
        }

        int idx = 0;
        for(auto& e : friendships)
        {
            int a = e[0], b = e[1];
            bool flag = false;
            for(auto& x : h1[a])
            {
                // cout << a << " " << x << endl;
                if(h1[b].find(x) != h1[b].end())
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                for(auto& x : h1[a]) h2[idx].insert(x);
                for(auto& x : h1[b]) h2[idx].insert(x);
            }
            idx++;
        }

        int res = INT_MAX;
        for(int i = 1; i <= n; i++)
        {
            int cnt = 0;
            vector<int> st(languages.size() + 1, 0);
            bool flag = true;
            for(auto& [k, e] : h2)
            {
                int a = friendships[k][0], b = friendships[k][1];
                if(h1[a].find(i) == h1[a].end() && st[a] == 0)
                {
                    cnt++;
                    st[a] = 1;
                }
                if(h1[b].find(i) == h1[b].end() && st[b] == 0)
                {
                    cnt++;
                    st[b] = 1;
                }
            }
            if(flag) res = min(res, cnt);
        }

        return res;
    }
};
// @lc code=end

