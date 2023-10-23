/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[2] > b[2];
    }
    static bool comper(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }

    // 排序 + 小根堆 小根堆保存前面已经上车的乘客当前乘客如果出发点大于前面的乘客出发点
    // 将前面的乘客出队
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 小根堆，对于优先队列队列头部是指向队列的尾部的
        priority_queue<vector<int>, vector<vector<int> >, decltype(&cmp)> q(cmp);
        // 出发点从小到大排序
        sort(trips.begin(), trips.end(), comper);
        if(trips[0][0] < capacity)
            return false;

        for(int i = 0; i < trips.size(); i++)
        {
            // 车上没有乘客时直接插入队列
            if(q.empty())
            {
                q.push({ trips[i] });
                capacity -= q.top()[0];
            }
            else
            {
                // 对于当前乘客将前面应该下车的乘客下车车的容量增加
                while(!q.empty() && q.top()[2] <= trips[i][1]) 
                {
                    capacity += q.top()[0];
                    q.pop();
                }
                // 当前的车的容量大于等于乘客人数入队，车容量减去乘客人数
                if(capacity - trips[i][0] >= 0)
                {
                    capacity -= trips[i][0];
                    q.push({ trips[i] });
                }
                else return false;
            }
        }

        return true;
    }
};
// @lc code=end

