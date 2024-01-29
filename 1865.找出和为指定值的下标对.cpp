/*
 * @lc app=leetcode.cn id=1865 lang=cpp
 *
 * [1865] 找出和为指定值的下标对
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class FindSumPairs {
public:
    vector<int> s1, s2;
    unordered_map<int, int> h1, h2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        s1 = nums1, s2 = nums2;

        for(auto& e : s1) h1[e]++;
        for(auto& e : s2) h2[e]++;
    }
    
    void add(int index, int val) {
        int x = s2[index];
        s2[index] += val;
        if(-- h2[x] == 0) h2.erase(x);
        h2[s2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(auto& e : s1)
        {
            int x = tot - e;
            res += h2[x];
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end

