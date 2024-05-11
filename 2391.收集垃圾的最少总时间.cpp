/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 *
 * [2391] 收集垃圾的最少总时间
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int s[N];

    int garbageCollection(vector<string>& words, vector<int>& nums) {
        for(int i = 1; i <= nums.size(); i++) 
            s[i] = s[i - 1] + nums[i - 1];

        int res = 0;

        auto find = [&](char c)->int
        {
            int sum = 0, pre = 0;
            for(int j = 0; j < words.size(); j++)
            {
                int cnt = 0;
                for(int i = 0; i < words[j].size(); i++)
                    if(words[j][i] == c) cnt++;

                if(cnt)
                {
                    sum += cnt + s[j] - s[pre];
                    pre = j;
                }
            }

            return sum;
        };  
        
        res += find('M');
        res += find('G');
        res += find('P');

        return res;
    }
};
// @lc code=end

