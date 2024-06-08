#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();

        auto find = [&](int i, int j, int sum)->int
        {
            vector<vector<int>> mem(n, vector<int>(n, -1));

            function<int(int, int)> dfs = [&](int l, int r)->int
            {
                if(l >= r) return 0;

                int& res = mem[l][r];
                if(res != -1) return res;

                res = 0;
                if(nums[l + 1] + nums[l] == sum) res = max(res, dfs(l + 2, r) + 1);
                if(nums[r - 1] + nums[r] == sum) res = max(res, dfs(l, r - 2) + 1);
                if(nums[l] + nums[r] == sum) res = max(res, dfs(l + 1, r - 1) + 1);

                return res;
            };

            return dfs(i, j);
        };

        int res1 = find(2, n - 1, nums[0] + nums[1]) + 1;
        int res2 = find(1, n - 2, nums[0] + nums[n - 1]) + 1;
        int res3 = find(0, n - 3, nums[n - 1] + nums[n - 2]) + 1;

        return max({res1, res2, res3});
    }
};