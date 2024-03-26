/*
 * @lc app=leetcode.cn id=1395 lang=cpp
 *
 * [1395] 统计作战单位数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    void update(vector<int>& tr, int idx, int c)
    {
        for(int i = idx; i < tr.size(); i += lowbit(i)) tr[i] += c;
    }
    
    int lowbit(int x)
    {
        return x & -x;
    }

    int query(vector<int>& tr, int idx)
    {
        int res = 0;
        for(int i = idx; i; i -= lowbit(i)) res += tr[i];

        return res;
    }

    int numTeams(vector<int>& nums) {
        int n = nums.size();
        vector<int> tr(1e5 + 10, 0);

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(nums[j] > nums[i])
                    res += query(tr, nums[j] - 1) - query(tr, nums[i]);
                else
                    res += query(tr, nums[i] - 1) - query(tr, nums[j]);
                update(tr, nums[j], 1);
            }
            for(int j = i + 1; j < n; j++)
            {
                update(tr, nums[j], -1);
            }
        }
        
        return res;
    }
};
// @lc code=end

