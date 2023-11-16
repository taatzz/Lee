/*
 * @lc app=leetcode.cn id=1311 lang=cpp
 *
 * [1311] 获取你好友已观看的视频
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 20010;
    int h[N], e[N], ne[N], idx = 0;
    int dist[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    vector<int> bfs(int x, int level)
    {
        queue<int> q;
        memset(dist, -1, sizeof dist);

        dist[x] = 0;
        q.push(x);
        vector<int> res;

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(dist[j] == -1)
                {
                    dist[j] = dist[t] + 1;
                    if(dist[j] == level)
                        res.push_back(j);
                    q.push(j);
                }
            }
        }

        return res;
    }

    static bool cmp(pair<string, int>& a, pair<string, int>& b)
    {
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        memset(h, -1, sizeof h);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < friends[i].size(); j ++)
                add(i, friends[i][j]), add(friends[i][j], i);
        }

        vector<int> t = bfs(id, level);
        unordered_map<string, int> hash;

        for(auto e : t)
        {
            for(int i = 0; i < watchedVideos[e].size(); i++)
                hash[watchedVideos[e][i]]++;
        }

        vector<pair<string, int> > tmp(hash.begin(), hash.end());
    
        // 按照出现频率排序，如果出现频率相同则按照string字典序排序
        sort(tmp.begin(), tmp.end(), cmp);

        vector<string> res;
        for(auto e : tmp)
            res.push_back(e.first);

        return res;
    }
};
// @lc code=end

