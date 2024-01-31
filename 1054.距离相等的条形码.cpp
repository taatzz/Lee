/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 10010;
    int s[N];

    vector<int> rearrangeBarcodes(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++)
        {
            s[nums[i]]++;
        }

        vector<PII> t;
        for(int i = 0; i < N; i++)
            if(s[i] != 0)
                t.push_back({s[i], i});

        sort(t.begin(), t.end(), greater<PII>());

        int idx = 0;
        vector<int> res(nums.size());
        for(int i = 0; i < t.size(); i++)
        {
            int x = t[i].first;
            while(x --)
            {
                res[idx] = t[i].second;
                idx += 2;
                if(idx >= res.size()) idx = 1;
            }
        }

        return res;
    }
};
// @lc code=end

