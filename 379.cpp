#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


// class Solution {
// public:
//     int areaOfMaxDiagonal(vector<vector<int>>& s) {
//         int res = 0;
//         float t = 0;

//         for(auto e : s)
//         {
//             if(sqrt(e[0] * e[0] + e[1] * e[1]) > t) res = e[0] * e[1];
//         }

//         return res;
//     }
// };


class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int i = e, j = f;
        
        bool flag = false;
        while(!flag && i >= 1 && j >= 1)
        {
            if(i == a && j == b) break;
            if(i == c && j == d)
                flag = true;
            i--;
            j--;
        }
        
        i = e, j = f;
        while(!flag && i >= 1 && j <= 8)
        {
            if(i == a && j == b) break;
            if(i  == c && j == d)
                flag = true;
            i--;
            j++;
        }
        i = e, j = f;
        while(!flag && i <= 8 && j >= 1)
        {
            if(i == a && j == b) break;
            if(i  == c && j == d)
                flag = true;
            i++;
            j--;
        }
        i = e, j = f;
        while(!flag && i <= 8 && j <= 8)
        {
            if(i == a && j == b) break;
            if(i  == c && j  == d)
                flag = true;
            i++;
            j++;           
        }
        
    
        if((a == e || b == f))
        {
            if(a == e)
            {
                int j = b;
                while(!flag && j >= 1)
                {
                    if(a == c && j == d) break;
                    if(a == e && j == f) flag = true;
                    j--;
                }
                j = b;
                while(!flag && j <= 8)
                {
                    if(a == c && j == d) break;
                    if(a == e && j == f) flag = true;
                    j++;
                }
            }
            else
            {
                int i = a;
                while(!flag && i >= 1)
                {
                    if(b == d && i == c) break;
                    if(b == f && i == e) flag = true;
                    i--;
                }
                i = a;
                while(!flag && i <= 8)
                {
                    if(b == d && i == c) break;
                    if(b == f && i == e) flag = true;
                    i++;
                }
            }
        }
        
        
        if(flag) return 1;
        return 2;
    }
};