/*
 * @lc app=leetcode.cn id=1835 lang=cpp
 *
 * [1835] 所有数对按位与结果的异或和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int cnt1[32], cnt2[32];

    void get(int x, bool flag)
    {
        for(int i = 0; i < 32; i++)
        {
            if((x & (1 << i)) == (1 << i))
            {
                if(flag) cnt1[i]++;
                else cnt2[i]++;
            }
        }
    }

    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        for(auto& e : arr1) get(e, true);
        for(auto& e : arr2) get(e, false);

        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            if(cnt1[i] == 0 || cnt2[i] == 0) continue;
            if((long long) cnt1[i] * cnt2[i] % 2 == 1) res += 1 << i;
        }

        return res;
    }
};
// @lc code=end

