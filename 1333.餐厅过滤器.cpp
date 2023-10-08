/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    static const int cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1] || (a[1] == b[1] && a[0] > b[0]);
    }

    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();
        vector<vector<int> > tmp;
        vector<int> res;
        
        for(int i = 0; i < n; i ++)
        {
            if(veganFriendly)
            {
                if(restaurants[i][2] && restaurants[i][3]  <= maxPrice 
                    && restaurants[i][4] <= maxDistance)
                    tmp.push_back(restaurants[i]);
            }
            else
                if(restaurants[i][3]  <= maxPrice && restaurants[i][4] <= maxDistance)
                    tmp.push_back(restaurants[i]);
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for(int i = 0; i < tmp.size(); i++)
            res.push_back(tmp[i][0]);
        
        return res;
    }
};
// @lc code=end

