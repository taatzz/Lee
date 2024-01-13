/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 *
 * [2182] 构造限制重复的字符串
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int a[26];
    string repeatLimitedString(string s, int k) {
        int n = s.size(), cnt = 0;
        // 先统计字符个数
        for(int i = 0; i < n; i++)
        {
            a[s[i] - 'a']++;
        }

        priority_queue<char, vector<char>, less<char>> q;
        for(int i = 0; i < 26; i++) 
            if(a[i] != 0) q.push(i + 'a');
        
        string res;
        int i = 25;
        while(i >= 0)
        {       
            // 从最大的开始
            if(a[i] == 0) 
            {
                i--;
                continue;
            }
            for(int j = 0; j < k && a[i] > 0; j++)
            {
                res += i + 'a';
                a[i]--;
            }
            // 当前最大的元素选择完才会选择下面的元素
            if(a[i] == 0) 
            {
                i--;
            }
            else
            {
                // 在堆中找到当前元素的次小元素
                while(q.size() && (q.top() >= i + 'a' || a[q.top() - 'a'] == 0)) q.pop();   
                // 堆中没有元素了直接返回
                if(q.size() == 0) return res;

                res += q.top();
                a[q.top() - 'a']--;
            }

        }

        return res;
    }
};
// @lc code=end

