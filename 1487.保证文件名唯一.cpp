/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> d;

        for(auto& e : names)
        {
            int k = d[e];
            if(k)
            {
                while(d[e + "(" + to_string(k) + ")"])
                    k++;
                d[e] = k;
                e += "(" + to_string(k) + ")";
            }
            d[e] = 1;
        }

        return names;
    }
};
// @lc code=end

