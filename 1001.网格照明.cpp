/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int dx[9] = { 0,1,0,-1,1,-1,-1,1,0 };
    int dy[9] = { 1,0,-1,0,1,1,-1,-1,0 };

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col, left, right; // 行 列 左右对角线
        unordered_map<long long, int> num;
        for(auto& e : lamps)
        {
            int a = e[0], b = e[1];
            long long x = (long long)a * n + b;
            if(num[x]) continue;
            row[a]++, col[b]++, left[a + b] ++, right[a - b] ++;
            num[x]++;
        }

        vector<int> res;
        for(auto& e : queries)
        {
            int x = e[0], y = e[1];
            if(row.count(x) || col.count(y) || left.count(x + y) || right.count(x - y))
            {
                res.push_back(1);
                for(int i = 0; i < 9; i++)
                {
                    int a = x + dx[i], b = y + dy[i];
                    if(a >= 0 && a < n && b >= 0 && b < n)
                    {
                        long long x = (long long)a * n + b;
                        if(num[x] != 0)
                        {
                            row[a]--;
                            if(row[a] == 0) row.erase(a);

                            col[b]--;
                            if(col[b] == 0) col.erase(b);

                            left[a + b]--;
                            if(left[a + b] == 0) left.erase(a + b);

                            right[a - b]--;
                            if(right[a - b] == 0) right.erase(a - b);

                            num.erase(x);
                        }
                    }
                }
            }
            else res.push_back(0);
        }

        return res;
    }
};
// @lc code=end

