/*
 * @lc app=leetcode.cn id=1766 lang=cpp
 *
 * [1766] 互质树
 */

// @lc code=start
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    vector<vector<int>> gcds; // 存于i互质的所有数
    vector<vector<int>> tmp; // 保存dfs过程中的遇到的nums中的数
    vector<int> res, dep; // dep保存每一个节点的深度

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(vector<int>& nums, int x, int d)
    {
        dep[x] = d;
        for(int val : gcds[nums[x]])
        {
            if(tmp[val].size() == 0) continue;

            // 在与nums[x] 互质的数中在当前路径中一定是最后的点深度最大
            int las = tmp[val].back();
            // 深度最大的点是答案
            if(res[x] == -1 || dep[las] > dep[res[x]]) res[x] = las;
        }
        tmp[nums[x]].push_back(x);

        for(int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            // 遍历到的点的深度不是-1，防止无限递归
            if(dep[j] == -1) dfs(nums, j, d + 1);
        }
        // 递归结束删除当前节点
        tmp[nums[x]].pop_back();
    }
//  在dfs的过程中当前路径上的所有的点中与当前点互质中的深度最大的点就是答案
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        int n = nums.size();
        res.resize(n, -1);
        dep.resize(n, -1);
        tmp.resize(51);
        gcds.resize(51);
        for(int i = 1; i <= 50; i++)
        {
            for(int j = 1; j <= 50; j++)
            {
                if(gcd(i, j) == 1) gcds[i].push_back(j);
            }
        }

        dfs(nums, 0, 1);

        return res;
    }
};
// @lc code=end

