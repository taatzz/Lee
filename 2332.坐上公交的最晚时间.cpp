/*
 * @lc app=leetcode.cn id=2332 lang=cpp
 *
 * [2332] 坐上公交的最晚时间
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        // 保存已经上车人的到达时间
        unordered_set<int> h;

        int j = 0, end = 0;
        for(int i = 0; i < buses.size() - 1; i++)
        {
            int x = buses[i], k = 0;
            int idx = upper_bound(passengers.begin() + j, passengers.end(), x) - passengers.begin();
            for(; j < idx && k < capacity; j++) 
            {
                k++;
                h.insert(passengers[j]);
            }
        }
        // 退后一趟车的所有可以上车的人
        end = upper_bound(passengers.begin() + j, passengers.end(), buses[buses.size() - 1]) - passengers.begin();
        for(; j < end && capacity; j++) 
        {
            h.insert(passengers[j]);
            capacity--;
        }
        int mx = 0;
        // 最后上完之后如果车上还有位置那么我们可以选择的最晚时间就是车到达的时间
        // 否则我们就只能最晚选择在最后一个人之前到达了
        if(capacity) mx = buses[buses.size() - 1];
        else mx = passengers[j - 1];
        
        // 最晚时间开始哪个时间没人到哪个时间就是答案
        for(int i = mx; i; i--) 
            if(h.count(i) == 0) return i;
        
        return 0;
    }
};
// @lc code=end

