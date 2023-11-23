/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> hash = { 
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
            };
        
        string res;
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == '&')
            {
                int j = i;
                while(j < text.size() && text[j] != ';') j++;
                string tmp = text.substr(i, j - i + 1);
                if(hash.find(tmp) != hash.end()) 
                {
                    res += hash[tmp];
                    i = j;
                    continue;
                }
            }
            res += text[i];
        }

        return res;
    }
};
// @lc code=end

