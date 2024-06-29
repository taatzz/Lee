/*
 * @lc app=leetcode.cn id=2657 lang=cpp
 *
 * [2657] 找到两个数组的前缀公共数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> cnta(51), cntb(51), res;

        for(int i = 0; i < A.size(); i++)
        {
            cnta[A[i]]++;
            cntb[B[i]]++;
            int cnt = 0;
            for(int i = 0; i < 51; i++)
            {
                if(cnta[i] == cntb[i] && cnta[i] == 1) cnt++;
            }
            res.push_back(cnt);
        }

        return res;
    }
};
// @lc code=end

