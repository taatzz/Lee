/*
 * @lc app=leetcode.cn id=2709 lang=cpp
 *
 * [2709] 最大公约数遍历
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static const int N = 200010;
    int p[N], size[N];

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < N; i++) p[i] = i;

        vector<int> h[N];
        auto get = [&](int x, int t)
        {
            bool flag = 1;
            for(int i = 2; i <= x / i; i++)
            {
                if(x % i == 0)
                {
                    h[i].push_back(t);
                    while(x % i == 0) x /= i;
                }
            }
            if(x > 1)
            {
                h[x].push_back(t);
            }
        };

        for(int i = 0; i < n; i++)
        {
            get(nums[i], i);
        }

        unordered_set<int> st;
        for(int i = 0; i < N; i++)
        {
            if(h[i].size() == 0) continue;
            for(auto& e : h[i])
            {
                int a = find(e), b = find(n + i);
                if(a != b) 
                {   
                    p[a] = b;
                }
            }
        }
        for(int i = 0; i < n; i++) st.insert(find(i));

        return st.size() == 1;
    }
};
// @lc code=end

