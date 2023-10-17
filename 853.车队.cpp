// @before-stub-for-debug-begin
#include <vector>
#include <string>
//#include "commoncppproblem853.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=853 lang=cpp
 *
 * [853] 车队
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first < b.first;
    }
    // 前车不会超过后车，所以需要比较前面的车是否可以追上前面的最慢车，需要从后向前遍历
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int> > tmp(n);
        vector<double> time(n);
        int res = 0;

        for(int i = 0; i < n; i++)
        {
           tmp[i] = pair<int, int>(position[i], speed[i]);
        }
        sort(tmp.begin(), tmp.end(),cmp);

        for(int i = 0; i < n; i++)
        {
            double t = (double)(target - tmp[i].first) / (double)tmp[i].second;
            time[i] = t;
        }

       stack<double> stk;
        for(int i=n-1;i>=0;i--){ //单调递增栈
            if(stk.empty()||stk.top()<time[i]){
                stk.push(time[i]);
            } //注意后车不可能超过前车，只能与前车同速，故如果后车用时更少，忽略即可，后车与前车同样用时也忽略后车
        }
        return stk.size(); //栈中元素个数即最终答案
    }
};
// @lc code=end

