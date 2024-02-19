/*
 * @lc app=leetcode.cn id=2059 lang=cpp
 *
 * [2059] 转化数字的最小运算数
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int bfs(vector<int>& nums, int start, int end)
    {
        queue<int> q;
        q.push(start);
        unordered_map<int, int> h;
        h[start] = 0;

        while(q.size())
        {
            int t = q.front();
            q.pop();

            // 为了防止超时只有在数据符合范围且没有遍历过时才能进行入队
            for(auto& e : nums)
            {
                int x = t + e;
                if(x == end) return h[t] + 1;
                if(x >= 0 && x <= 1000 && h.find(x) == h.end()) 
                    q.push(x), h[x] = h[t] + 1;

                x = t - e;
                if(x == end) return h[t] + 1;
                if(x >= 0 && x <= 1000 && h.find(x) == h.end()) 
                    q.push(x), h[x] = h[t] + 1;
            
                x = t ^ e;
                if(x == end) return h[t] + 1;
                if(x >= 0 && x <= 1000 && h.find(x) == h.end()) 
                    q.push(x), h[x] = h[t] + 1;
            }
        }

        return -1;
    }

    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        return bfs(nums, start, goal);
    }
};
// @lc code=end

