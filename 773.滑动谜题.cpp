/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string end = "123450";
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int bfs(string start, int n, int m)
    {
        unordered_map<string, int> h;
        queue<string> q;
        q.push(start);
        h[start] = 0;

        while(q.size())
        {
            auto t = q.front();
            q.pop();
            if(t == end) return h[t];
            int ver = 0, dist = h[t];
            for(int i = 0; i < t.size(); i++) 
                if(t[i] == '0') ver = i;
            int x = ver / m, y = ver % m;

            for(int i = 0; i < 4; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if(a < 0 || a >= n || b < 0 || b >= m) continue;
                swap(t[a * m + b], t[ver]);
                if(h.find(t) == h.end())
                {
                    q.push(t);
                    h[t] = dist + 1;
                }
                swap(t[a * m + b], t[ver]);
            }
        }

        return -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        string t;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                t += to_string(board[i][j]);
            }
        }
        

        return bfs(t, n, m);
    }
};
// @lc code=end

