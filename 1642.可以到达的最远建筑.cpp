/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     bool check(vector<int>& nums, int x, int b, int l)
//     {
//         int n = nums.size();
//         vector<int> dist(x, 0);
//         for(int i = 0; i < x; i ++)
//         {
//             dist[i] = nums[i + 1] - nums[i];
//         }
//         sort(dist.begin(), dist.end());

//         for(int i = x - 1; i >= 0; i--)
//         {
//             if(dist[i] < 0) break;
//             if(l) l--;
//             else if(b >= dist[i]) b -= dist[i];
//             else return false;
//         }

//         return true;
//     }

//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         int l = 0, r = heights.size() - 1;

//         while(l < r)
//         {
//             int mid = (l + r + 1) >> 1;
//             if(check(heights, mid, bricks, ladders)) l = mid;
//             else r = mid - 1;
//         }

//         return l;
//     }
// };
// @lc code=end

#include <queue>

class Solution {
public:

    // 贪心。对于当前需要砖块或者梯子的地方，我们进行补全，但是要想走的更远就需要最高的地方使用梯子，所以我们使用优先队列
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> q;

        for(int i = 0; i < heights.size() - 1; i++)
        {
            if(heights[i + 1] > heights[i])// 高度差需要砖块或者梯子
            {
                int dist = heights[i + 1] - heights[i]; // 将当前的高度差加入队列
                q.push(dist);
                if(q.size() > ladders) // 梯子不够就只能使用砖块了
                {
                    int x = q.top();
                    q.pop();
                    bricks -= x;
                    if(bricks < 0) // 如果当前的高度砖块无法满足，当前就是可以到达的最远地方
                    {
                        return i;
                    }
                }
            }
        }

        return n - 1;
    }
};

