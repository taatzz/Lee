/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool cmp(vector<int>& a, int i, vector<int>& b, int j)
    {
        int m = a.size(), n = b.size();
        while(i < m && j < n)
        {
            if(a[i] == b[j]) i++, j++;
            else break;
        }
        if(i == m) return false;
        if(j == n) return true;

        if(a[i] > b[j]) return true;
        else return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();

        auto find = [&](vector<int>& nums, int x)->vector<int>
        {
            if(x == 0) return {};
            vector<int> stk;
            int n = nums.size();
            for(int i = 0; i < nums.size(); i++)
            {
                while(stk.size() and stk.back() < nums[i] and stk.size() + n - i > x)
                {
                    stk.pop_back();
                }
                stk.push_back(nums[i]);
            }
            stk.resize(x);

            return stk;
        };

        auto merge = [&](vector<int>& subsequence1, vector<int>& subsequence2)
        {
            int x = subsequence1.size(), y = subsequence2.size();
            if (x == 0) {
                return subsequence2;
            }
            if (y == 0) {
                return subsequence1;
            }
            int mergeLength = x + y;
            vector<int> merged(mergeLength);
            int index1 = 0, index2 = 0;
            for (int i = 0; i < mergeLength; i++) {
                if (cmp(subsequence1, index1, subsequence2, index2)) {
                    merged[i] = subsequence1[index1++];
                } else {
                    merged[i] = subsequence2[index2++];
                }
            }
            return merged;

        };

        vector<int> res(k, 0);
        for(int i = max(0, k - n); i <= min(k, m); i++)
        {
            int other = k - i;

            vector<int> a = find(nums1, i);
            vector<int> b = find(nums2, other);

            vector<int> t = merge(a, b);
            if(cmp(t, 0, res, 0)) res = t;
        }

        return res;
    }
};
// @lc code=end

