/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> tmp;

    bool is_ip(string s, int start, int end)
    {
        int i = start;
        if(start > end)
            return false;
        if(s[start] == '0' && start != end)
            return false;
        int num = 0;
        while(i <= end)
        {
            if(s[i] > '9' || s[i] < '0')
                return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255)
                return false;
        }
        return true;
    }

    void dfs(int start, int num, string& s)
    {
        if(num == 3)
        {
            if(is_ip(s, start, s.size() - 1))
                tmp.push_back(s);
            return;
        }

        for(int i = start; i < s.size(); i++)
        {
            if(is_ip(s, start, i))
            {
                s.insert(s.begin() + i + 1, '.');
                num++;
                dfs(i + 2, num, s);
                num--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
            return tmp;

        dfs(0, 0, s);

        return tmp;
    }
};
// @lc code=end

