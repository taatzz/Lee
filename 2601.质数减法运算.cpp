/*
 * @lc app=leetcode.cn id=2601 lang=cpp
 *
 * [2601] 质数减法运算
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    vector<int> primes;
    bool st[N];

    void get_primes()
    {
        for(int i = 2; i < N; i++)
        {
            if(!st[i]) 
            {
                primes.push_back(i);
                for(int j = i + i; j < N; j += i)
                    st[j] = 1;
            }
            
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        primes.push_back(0);
        get_primes();

        int pre = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= pre) return false;
            pre = nums[i] - *(--lower_bound(primes.begin(), primes.end(), nums[i] - pre));
        }

        return true;
    }
};
// @lc code=end

