/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 贪心解：将数组排序，如果当前体重最小的和体重最大的没有超出限制，那么就只需要一个船，反之需要两只
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());

        int res = 0;
        for(int i = 0, j = n - 1; i <= j;)
        {
            if(i == j)
            {
                res++;
                break;
            }
            else if(people[i] + people[j] <= limit)
            {
                res++;
                i++;
                j--;
            }
            else
            {
                res++; 
                j--;
            }
        }

        return res;
    }
};
// @lc code=end

