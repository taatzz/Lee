/*
 * @lc app=leetcode.cn id=1504 lang=cpp
 *
 * [1504] 统计全 1 子矩形
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     static const int N = 200;
//     int s[N][N];

//     int numSubmat(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();

//         for(int i = 1; i <= m; i++)
//             for(int j = 1; j <= n; j++ )
//                 s[i][j] = s[i-1][j] + s[i][j-1] - s[i - 1][j - 1] + mat[i-1][j-1];

//         int res = 0;
//         // n^4 会超时
//         for(int h = 1; h <= m; h++)
//         {
//             for(int w = 1; w <= n; w ++)
//             {
//                 for(int i = 0; i <= m - h; i ++)
//                 {
//                     for(int j = 0; j <= n - w; j++)
//                     {
//                         int x1 = i + 1, y1 = j + 1;
//                         int x2 = x1 + h - 1, y2 = y1 + w -1;

//                         int t = s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
//                         if(t == (x2 - x1 + 1) * (y2 - y1 + 1))
//                             res++;
//                     }
//                 }
//             }
//         }  

//         return res;  
//     }
// };
// @lc code=end

class Solution {
public:
    static const int N = 200;
    int s[N][N];

    bool check(int x1, int y1, int x2, int y2)
    {
        x1 += 1, y1 += 1, x2 += 1, y2 += 1;
        int t = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
        return t == (x2 - x1 + 1) * (y2 - y1 + 1); 
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++ )
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i - 1][j - 1] + mat[i-1][j-1];

        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0) continue;
                for(int k = j; k < n; k ++)
                {
                    if(mat[i][k] != 1) break;
                    int l = i, r = m - 1;
                    while(l < r)
                    {
                        int mid = (l + r + 1) >> 1;
                        if(check(i, j, mid, k)) l = mid;
                        else r = mid - 1;
                    }
                    cout << l << " ";
                    res += l - i + 1;
                }  
            }
        }

        return res;  
    }
};