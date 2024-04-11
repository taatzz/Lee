/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;

    int minimumJumps(vector<int>& nums, int a, int b, int x) {
        unordered_set<int> h(nums.begin(), nums.end());

        queue<pii> q;
        q.push({0, 1});
        int n = 6000;
        bool st[6000][2];
        memset(st, 0, sizeof st);
        st[0][1] = 1;

        int cnt = 0;
        while(q.size())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto t = q.front();
                q.pop();
                if(t.first == x) return cnt;

                vector<pii> next = {{t.first + a, 1}};
                if(t.second & 1)
                {
                    next.push_back({t.first - b, 0});
                }
                
                for(auto [j, l] : next)
                {
                    if(j >= 0 && j < n && !h.count(j) && !st[j][l])
                    {
                        st[j][l] = 1;
                        q.push({j, l});
                    }
                }
            }

            cnt++;
        }


        return -1;
    }
};
// @lc code=end

