/*
 * @lc app=leetcode.cn id=2615 lang=cpp
 *
 * [2615] 等值距离和
 */

// @lc code=start
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<long long> res;

    void find(vector<int>& nums)
    {
        int n = nums.size();
        vector<long long> s(n + 1);
        if(n == 1) res[nums[0]] = 0;
        else
        {
            for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
            for(int i = 0; i < n; i++)
            {
                long long target = nums[i];
                long long left = (long long)target * i - s[i];
                long long right = s[n] -  s[i] - (long long)(n - i) * target;
                res[nums[i]] = left + right;
            }
        }
    }

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> h;
        res.resize(n);
        for(int i = 0; i < n; i++)
        {
            h[nums[i]].push_back(i);
        }
    
        for(auto& e : h)
        {
            find(e.second);
        }

        return res;
    }
};
// @lc code=end

