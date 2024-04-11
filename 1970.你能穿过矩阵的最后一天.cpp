/*
 * @lc app=leetcode.cn id=1970 lang=cpp
 *
 * [1970] 你能穿过矩阵的最后一天
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int r, c;
    typedef pair<int, int> pii;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };

    bool check(vector<vector<int>> nums, int x)
    {
        vector<vector<bool>> st(r, vector<bool>(c, 0));

        for(int i = 0; i <= x; i++)
        {
            int a = nums[i][0] - 1, b = nums[i][1] - 1;
            st[a][b] = 1;
        }

        queue<pii> q;
        for(int i = 0; i < c; i++)
            if(!st[0][i]) 
            {
                q.push({0, i});
                st[0][i] = 1;
            }

        while(q.size())
        {
            auto t = q.front();
            q.pop();
            if(t.first == r - 1) return true;
            
            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= 0 && a < r && b >= 0 && b < c && !st[a][b])
                {
                    st[a][b] = 1;
                    q.push({a, b});
                }
            }
        }

        return false;
    }


    int latestDayToCross(int row, int col, vector<vector<int>>& nums) {
        int n = nums.size();
        r = row, c = col;

        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(nums, mid)) l = mid;
            else r = mid - 1;
        }

        return l + 1;
    }
};
// @lc code=end

