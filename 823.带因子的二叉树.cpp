/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        // dp[p] += dp[lc] * dp[rc];
        unordered_map<int, long long> hash;
        int mod = 1e9 + 7;
        long long res = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            int left = 0, right = i - 1;
            // 每个值作为一个单独的节点都是符合的
            // 必须要在前面加，不然后续该节点作为叶子节点时就算少了
            hash[arr[i]] = 1;
            while(left <= right)
            {
                if((long long)arr[left] * arr[right] > arr[i]) right --;
                else if((long long)arr[left] * arr[right] < arr[i]) left ++;
                else
                {
                    long long c1 = hash[arr[left]],c2 = hash[arr[right]];
        
                    if(arr[left] != arr[right])
                        hash[arr[i]] += (c1 * c2 * 2 ) % mod;
                    else 
                        hash[arr[i]] += (c1 * c2) % mod;
                    right--;
                }
            }

            res += hash[arr[i]];
        }

        return res % mod;
    }
};
// @lc code=end

