/*
 * @lc app=leetcode.cn id=1255 lang=cpp
 *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> t;
    vector<string> path;
    unordered_map<int, int> h;
    int res = 0;

    void dfs(vector<string>& words, int x)
    {
        int n = words.size();
        if(x == n) 
        {
            vector<int> cnt(26);
            int sum = 0;
            for(int i = 0; i < path.size(); i++)
            {
                int s = 0;
                bool flag = true;
                vector<int> tmp(26);
                for(int k = 0; k < path[i].size(); k++)
                {
                    int d = path[i][k] - 'a';
                    
                    if(cnt[d] + tmp[d] < h[d]) 
                    {
                        tmp[d]++;
                        s += t[d];
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) 
                {
                    sum += s;
                    for(int k = 0; k < 26; k++) cnt[k] += tmp[k];
                }
            }
            res = max(res, sum);

            return;
        }

        path.push_back(words[x]);
        dfs(words, x + 1);
        path.pop_back();

        dfs(words, x + 1);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        t = score;
        for(auto& e : letters)
        {
            int a = e - 'a';
            h[a]++;
        }

        dfs(words, 0);

        return res;
    }
};
// @lc code=end

