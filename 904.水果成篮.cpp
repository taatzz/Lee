/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> h;

        int j = 0, i = 0, res = 0, cnt = 0;
        for(; i < n; i++)
        {
            if(++h[fruits[i]] == 1) // 当前水果第一次放进篮子中
            {
                cnt++;
                while(cnt > 2) // 篮子中只能有两种水果
                {
                    // 将其中的一种水果拿出去拿完一个之后种类减一
                    if(--h[fruits[j++]] == 0) cnt--;
                }
                
            }
            // 记录长度最大值
            res = max(res, i - j + 1);
        }

        return res;
    }
};
// @lc code=end

