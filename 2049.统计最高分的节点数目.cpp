/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 200010;
    PII tree[N];
    int sum;
    long long mx = 0, res = 0;

    int dfs(int root)
    {
        int left = 0, right = 0;
        if(tree[root].first != -1)
            left = dfs(tree[root].first);
        if(tree[root].second != -1)
            right = dfs(tree[root].second);

        long long cnt = (long long)(left == 0 ? 1 : left) * 
                                   (right == 0 ? 1 : right) * 
        (sum - left - right - 1 == 0 ? 1 : sum - left - right - 1);
        
        if(cnt > mx)
        {
            mx = cnt;
            res = 0;
            res++;
        }
        else if(cnt == mx) res++;
        
        return 1 + right + left;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int root = 0;
        int n = parents.size();
        sum = n;
        for(int i = 0; i < n; i++) tree[i] = {-1, -1};

        for(int i = 1; i < n; i++)
        {
            int x = parents[i];
            if(tree[x].first == -1) tree[x].first = i;
            else tree[x].second = i;
        }

        dfs(0);

        return res;
    }
};
// @lc code=end

