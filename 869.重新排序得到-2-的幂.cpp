/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_set<int> h;
    int cnt[10];

    void get()
    {
        for(int i = 1; i < (int)1e9 + 10; i *= 2) h.insert(i);
    }

    bool reorderedPowerOf2(int n) {
        get();
        while(n)
        {
            cnt[n % 10]++;
            n /= 10;
        }

        for(auto e : h)
        {
            vector<int> cur(10);
            bool flag = true;
            while(e)
            {
                cur[e % 10]++;
                e /= 10;
            }
            for(int i = 0; i < 10; i++) 
                if(cur[i] != cnt[i]) 
                    flag = false;
            if(flag)
                return true;
        }

        return false;
    }
};
// @lc code=end

