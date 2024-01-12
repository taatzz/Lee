/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> h;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(auto e: arr) h[e]++;
        if(h[0] % 2) return false;

        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(h.find(arr[i]) == h.end()) continue;
            int x = arr[i] * 2;
     
            if(h.find(x) != h.end())
            {
                cnt++;
                h[x] --;
                h[arr[i]]--;
                if(h[x] == 0) h.erase(x);
            }
            if(h[arr[i]] == 0) h.erase(arr[i]);
        }

        return cnt == n / 2;
    }
};
// @lc code=end

