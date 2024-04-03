/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0) st.push(i);
            else
            {
                while(st.size())
                {
                    int tmp = st.top();
                    if(nums[tmp] > abs(nums[i]))
                    {
                        nums[i] = 0;
                        break;
                    }
                    else if(nums[tmp] == abs(nums[i]))
                    {
                        st.pop();
                        nums[tmp] = nums[i] = 0;
                        break;
                    }
                    else
                    {
                        nums[tmp] = 0;
                        st.pop();
                    }
                }
            }
        }

        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        return nums;
    }
};
// @lc code=end

