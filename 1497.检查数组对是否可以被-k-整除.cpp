/*
 * @lc app=leetcode.cn id=1497 lang=cpp
 *
 * [1497] 检查数组对是否可以被 k 整除
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> h;
        for(int i = 0; i < n; i++) h[(arr[i] % k + k) % k] ++;

        for(auto [num, cnt] : h)
        {
            if(num == 0 && cnt & 1) return false;
            if(cnt != h[(k - num) % k]) return false;
        }

        return true;
    }
};
// @lc code=end

