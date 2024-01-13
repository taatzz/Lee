/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 因为要拆分成更多数目的偶数所以应该按照偶数从小到大的顺序进行拆分
    // 因为都是偶数（偶数 + 偶数 = 偶数）所以我们从小到大的将目标数进行拆分，然后最后一项不够了直接补到前面一项
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2) return {};

        vector<long long> res;
        long long sum = 2;

        while(sum <= finalSum)
        {
            res.push_back(sum);
            finalSum -= sum;
            sum += 2;
        }
        res.back() += finalSum;

        return res;
    }
};
// @lc code=end

