/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 50010;
    int s[N];

    bool check(string& str, int x, int k)
    {
        int n = str.size();
        for(int i = x - 1; i < n; i++)
        {
            int j = i - x + 1;
            int t = s[i + 1] - s[j];
            if(t <= k || x - t <= k) return true; 
        }
        return false;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        for(int i = 1; i <= n; i++) 
        {
            int x = answerKey[i - 1] == 'T' ? 1 : 0;
            s[i] = s[i - 1] + x;
        }

        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(answerKey, mid, k)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

