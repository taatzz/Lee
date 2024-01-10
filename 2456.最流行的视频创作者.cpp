/*
 * @lc app=leetcode.cn id=2456 lang=cpp
 *
 * [2456] 最流行的视频创作者
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, string> PIS;
    struct cmp{
        bool operator()(PIS& a, PIS& b)
        {
            if(a.first != b.first) return a.first < b.first;
            else return a.second > b.second; 
        }
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> sum;
        int n = ids.size();
        unordered_map<string, priority_queue<PIS, vector<PIS>, cmp> > h;

        long long mx = 0;
        vector<string> t;
        for(int i = 0; i < n; i++)
        {
            sum[creators[i]] += views[i];
            h[creators[i]].push({ views[i],ids[i] });
            if(sum[creators[i]] > mx)
            {
                mx = sum[creators[i]];
                t.clear();
                t.push_back(creators[i]);
            }
            else if(sum[creators[i]] == mx)
            {
                if(t.empty())
                    t.push_back(creators[i]);
                else if(t.back() != creators[i]) 
                    t.push_back(creators[i]);
            }
        }

        vector<vector<string>> res;

        for(auto e : t)
        {
            res.push_back({ e,h[e].top().second });
        }

        return res;
    }
};
// @lc code=end

