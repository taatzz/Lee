/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    unordered_set<long long> un_use;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    int mx = 1e5;
    long long base = 131;

    bool bfs(vector<int>& t, vector<int>& s)
    {
        int x = t[0], y = t[1];
        int n = 1e6;
        queue<pii> q;
        q.push({x, y});
        unordered_set<long long> st;
        st.insert(x * base + y);

        while(q.size() && st.size() <= mx)
        {
            auto t = q.front();
            q.pop();
            if(t.first == s[0] and t.second == s[1]) return true;

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                long long tmp = a * base + b;
                if(a >= 0 && a < n && b >= 0 && b < n && !st.count(tmp) && !un_use.count(tmp))
                {
                    q.push({a, b});
                    st.insert(tmp);
                }
            }
        }

        return st.size() > mx;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
        int n = blocked.size();
        // mx = n * (n - 1) / 2;
        for(auto& e : blocked)
        {
            int a = e[0], b = e[1];
            un_use.insert(a * base + b);
        }

        return bfs(s, t) and bfs(t, s);
    }
};
// @lc code=end

