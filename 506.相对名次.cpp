/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int> > arr;
        vector<string> res(score.size());
        string desc[3] = { "Gold Medal","Silver Medal","Bronze Medal"  };

        for(int i = 0; i < score.size(); i++)
        {
            arr.push_back(make_pair(-score[i], i));
        }
        sort(arr.begin(), arr.end());

        for(int i = 0; i < score.size(); i++)
        {
            if(i >= 3)
            {
                res[arr[i].second] = to_string(i + 1);
            }
            else
                res[arr[i].second] = desc[i];
        }

        return res;
    }
};
// @lc code=end

