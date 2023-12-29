/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();

//         int res = 0, cnt = 0;
//         for(int i = 0, j = 0; i < n; i++)
//         {
//             if(nums[i] % 2 != 0) cnt++;

//             if(cnt == k)
//             {
//                 int tmp = i + 1, num = 0;
//                 while(tmp < n && nums[tmp] % 2 == 0) tmp++;
//                 while(nums[j] % 2 == 0) 
//                 {
//                     if(nums[j] % 2) cnt--;
//                     num++;
//                     j++;
//                 }

//                 // cout << (tmp - i + 1) << " " << num + 1 << endl;

//                 res += (tmp - i) * (num + 1);
//                 j++;
//                 cnt--;
//             }
//         }

//         return res;
//     }
// };
// @lc code=end


class Solution {
public:
    static const int N = 50010;
    long long s[N];

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++) 
        {
            if(nums[i] % 2) s[i] = s[i - 1] + 1;
            else s[i] = s[i - 1];
        }

        int res = 0;
        unordered_map<int, int> h;
        h.insert({0, 1});
        for(int i = 0; i < n; i++)
        {
            int t = h[i] - k;
            if(h.find(t) != h.end()) res += h[t];
            h[s[i]]++;
        }

        return res;
    }
};

